//
// Created by chiel on 12-02-20.
//

#pragma once // VISION_GRAYSCALE_HPP

#include "RGB.hpp"

template <typename ValueType>
class Intensity {
public:
	ValueType value;

	Intensity() : value{} {
	}

	template <typename VType>
	Intensity(VType &&value) : value{value} {
	}

	Intensity(RGB<ValueType> rgb)
	    : // linear RGB to Luminance
	      value{ValueType(.2126 * rgb.r + .7152 * rgb.g + .0722 * rgb.b)} {
	}
};
