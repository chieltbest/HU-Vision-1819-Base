/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights
 * Reserved Unauthorized copying of this file, via any medium is strictly prohibited Proprietary and
 * confidential
 */

#pragma once

#include "IntensityImage.h"

#include <DynamicImage.hpp>

class IntensityImageStudent : public DynamicImage<Intensity, IntensityImage> {
public:
	IntensityImageStudent();
	IntensityImageStudent(const IntensityImageStudent &other);
	IntensityImageStudent(int width, int height);
	~IntensityImageStudent() override;

	void set(int width, int height) override;
	void set(const IntensityImageStudent &other);

	void setPixel(int x, int y, Intensity pixel) override;
	void setPixel(int i, Intensity pixel) override;

	[[nodiscard]] Intensity getPixel(int x, int y) const override;
	[[nodiscard]] Intensity getPixel(int i) const override;
};
