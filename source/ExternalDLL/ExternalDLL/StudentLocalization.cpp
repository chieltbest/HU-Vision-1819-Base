#include "StudentLocalization.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image,
                                                   FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image,
                                               FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image,
                                                  FeatureMap &features) const {
	const double phi_ratio{-(1 - std::sqrt(5.0)) / 2};
	const double phi_half{phi_ratio - .5};

	auto head_top        = features.getFeature(Feature::FEATURE_HEAD_TOP),
	     head_left_side  = features.getFeature(Feature::FEATURE_HEAD_LEFT_SIDE),
	     head_right_side = features.getFeature(Feature::FEATURE_HEAD_RIGHT_SIDE),
	     nose_bottom     = features.getFeature(Feature::FEATURE_NOSE_BOTTOM),
	     mouth_center    = features.getFeature(Feature::FEATURE_MOUTH_CENTER),
	     chin            = features.getFeature(Feature::FEATURE_CHIN);

	// proportions in the average human face using the golden ratio
	double head_left = head_left_side.getX(), head_right = head_right_side.getX(),
	       head_mid         = head_top.getX();
	double head_total_width = head_right - head_left, head_left_width = head_mid - head_left,
	       head_right_width = head_right - head_mid;
	double left_eye_inner   = head_mid - head_left_width * phi_half,
	       right_eye_inner  = head_mid + head_right_width * phi_half,
	       left_eye_outer   = head_left + head_left_width * phi_ratio / 2,
	       right_eye_outer  = head_right - head_right_width * phi_ratio / 2;

	double head_height = chin.getY() - head_top.getY(),
	       pupil_y     = (chin.getY() + head_top.getY()) / 2;

	const auto nose_size = int(head_height / 10);
	auto nose_p_x        = int(nose_bottom.getX());
	auto nose_p_y        = int(nose_bottom.getY());
	auto nose_q_x        = int(nose_bottom.getX());
	auto nose_q_y        = int(nose_bottom.getY());

	for (int y = int(nose_bottom.getY()) - nose_size; y <= nose_bottom.getY(); ++y) {
		for (int x = int(nose_bottom.getX()) - nose_size; x < nose_bottom.getX(); ++x) {
			auto p = image.getPixel(x, y);
			if (!p) {
				if (x <= nose_p_x) {
					nose_p_y = y;
					nose_p_x = x;
				}
				break;
			}
		}

		for (int x = int(nose_bottom.getX()) + nose_size; x > nose_bottom.getX(); --x) {
			if (!image.getPixel(x, y)) {
				if (x >= nose_q_x) {
					nose_q_y = y;
					nose_q_x = x;
				}
				break;
			}
		}
	}

	double head_left_nose = nose_bottom.getX(), head_right_nose = nose_bottom.getX();

	for (int x = int(nose_bottom.getX()) - nose_size; x > 0; --x) {
		if (!image.getPixel(x, int(nose_bottom.getY()))) {
			head_left_nose = x;
			break;
		}
	}
	for (int x = int(nose_bottom.getX()) + nose_size; x < image.getWidth(); ++x) {
		if (!image.getPixel(x, int(nose_bottom.getY()))) {
			head_right_nose = x;
			break;
		}
	}

	const unsigned hist_size = nose_size * 2;
	const int hist_start     = int(nose_bottom.getY()) - nose_size * 3;

	std::vector<unsigned> l_eye_hist{};
	std::vector<unsigned> r_eye_hist{};
	l_eye_hist.resize(hist_size);
	r_eye_hist.resize(hist_size);

	for (int y = hist_start; y < hist_start + hist_size; ++y) {
		for (int x = int(nose_bottom.getX()) - nose_size * 2; x < nose_bottom.getX(); ++x) {
			if (!image.getPixel(x, y)) {
				l_eye_hist[y - hist_start]++;
			}
		}

		for (int x = int(nose_bottom.getX()) + nose_size * 2; x > nose_bottom.getX(); --x) {
			if (!image.getPixel(x, y)) {
				r_eye_hist[y - hist_start]++;
			}
		}
	}

	double l_eye_start = hist_start, l_eye_end = hist_start;
	double r_eye_start = hist_start, r_eye_end = hist_start;
	constexpr int eye_value_tresh = 5;

	for (auto &[start, end, hist] : {
	             std::tuple<double &, double &, std::vector<unsigned> &>{l_eye_start, l_eye_end,
	                                                                     l_eye_hist},
	             std::tuple<double &, double &, std::vector<unsigned> &>{r_eye_start, r_eye_end,
	                                                                     r_eye_hist},
	     }) {
		int y = hist_start;
		for (; y < hist_start + hist_size; ++y) {
			if (hist[y] >= eye_value_tresh) {
				break;
			}
		}
		start = y;
		for (; y < hist_start + hist_size; ++y) {
			if (hist[y] < eye_value_tresh) {
				break;
			}
		}
		end = y;
	}

	Feature left_eye{Feature::FEATURE_EYE_LEFT_RECT};
	left_eye.addPoint({nose_bottom.getX() - nose_size * 2, l_eye_start});
	left_eye.addPoint({nose_bottom.getX(), l_eye_end});

	Feature right_eye{Feature::FEATURE_EYE_RIGHT_RECT};
	right_eye.addPoint({nose_bottom.getX(), r_eye_start});
	right_eye.addPoint({nose_bottom.getX() + nose_size * 2, r_eye_end});

	features.putFeature(left_eye);
	features.putFeature(right_eye);

	features.putFeature({Feature::FEATURE_NOSE_END_LEFT, {double(nose_p_x), double(nose_p_y)}});
	features.putFeature({Feature::FEATURE_NOSE_END_RIGHT, {double(nose_q_x), double(nose_q_y)}});

	features.putFeature(
	        {Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM, {head_left_nose, nose_bottom.getY()}});
	features.putFeature(
	        {Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM, {head_right_nose, nose_bottom.getY()}});

	return true;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image,
                                            FeatureMap &features) const {
	return false;
}
