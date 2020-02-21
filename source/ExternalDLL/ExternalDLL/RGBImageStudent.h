/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights
 * Reserved Unauthorized copying of this file, via any medium is strictly prohibited Proprietary and
 * confidential
 */

#pragma once

#include "PixelType.h"
#include "RGBImage.h"

#include <DynamicImage.hpp>

class RGBImageStudent : public DynamicImage<RGB, RGBImage> // the RGB image implementation
{
public:
	RGBImageStudent();
	RGBImageStudent(const RGBImageStudent &other);
	RGBImageStudent(int width, int height);
	~RGBImageStudent() override;

	void set(int width, int height) override;
	void set(const RGBImageStudent &other);

	void setPixel(int x, int y, RGB pixel) override;
	void setPixel(int i, RGB pixel) override;

	[[nodiscard]] RGB getPixel(int x, int y) const override;
	[[nodiscard]] RGB getPixel(int i) const override;
};
