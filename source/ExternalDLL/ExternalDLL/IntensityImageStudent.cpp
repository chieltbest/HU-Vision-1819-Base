#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : DynamicImage<Intensity, IntensityImage>{} {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) = default;

IntensityImageStudent::IntensityImageStudent(const int width, const int height)
    : DynamicImage<Intensity, IntensityImage>{width, height} {
}

IntensityImageStudent::~IntensityImageStudent() = default;

void IntensityImageStudent::set(const int width, const int height) {
	DynamicImage<Intensity, IntensityImage>::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	DynamicImage<Intensity, IntensityImage>::set(other);
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	DynamicImage<Intensity, IntensityImage>::setPixel(x, y, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	DynamicImage<Intensity, IntensityImage>::setPixel(i, pixel);
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return DynamicImage<Intensity, IntensityImage>::getPixel(x, y);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return DynamicImage<Intensity, IntensityImage>::getPixel(i);
}
