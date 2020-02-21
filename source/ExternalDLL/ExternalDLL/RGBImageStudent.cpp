#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : Base{} {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) = default;

RGBImageStudent::RGBImageStudent(const int width, const int height) : Base{width, height} {
}

RGBImageStudent::~RGBImageStudent() = default;

void RGBImageStudent::set(const int width, const int height) {
	Base::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	Base::set(other);
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	Base::setPixel(x, y, pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	Base::setPixel(i, pixel);
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return Base::getPixel(x, y);
}

RGB RGBImageStudent::getPixel(int i) const {
	return Base::getPixel(i);
}
