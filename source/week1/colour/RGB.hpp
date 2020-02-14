//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_RGB_HPP

#include <limits>
#include <type_traits>

#include "Intensity.hpp"

template <typename ValueType = char>
class RGB {
public:
	ValueType r, g, b;

	template <typename RType, typename GType, typename BType>
	RGB(RType &&r, GType &&g, BType &&b) : r{r}, g{g}, b{b} {
	}

	std::enable_if_t<std::is_integral_v<ValueType>, Intensity> get_intensity() {
		auto max = std::numeric_limits<ValueType>::max();
		return RGB{double(r) / max, double(g) / max, double(b) / max}.get_intensity();
	}

	std::enable_if_t<!std::is_integral_v<ValueType>, Intensity> get_intensity() {
		// linear RGB to Luminance
		return {.2126 * r + .7152 * g + .0722 * b};
	}
};
