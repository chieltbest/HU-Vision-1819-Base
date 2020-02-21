#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : DynamicImage<RGB, RGBImage>{} {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) = default;

RGBImageStudent::RGBImageStudent(const int width, const int height)
    : DynamicImage<RGB, RGBImage>{width, height} {
}

RGBImageStudent::~RGBImageStudent() = default;

void RGBImageStudent::set(const int width, const int height) {
	DynamicImage<RGB, RGBImage>::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	DynamicImage<RGB, RGBImage>::set(other);
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	DynamicImage<RGB, RGBImage>::setPixel(x, y, pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	DynamicImage<RGB, RGBImage>::setPixel(i, pixel);
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return DynamicImage<RGB, RGBImage>::getPixel(x, y);
}

RGB RGBImageStudent::getPixel(int i) const {
	return DynamicImage<RGB, RGBImage>::getPixel(i);
}
