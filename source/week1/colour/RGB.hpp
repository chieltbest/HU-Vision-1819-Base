//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_RGB_HPP

#include <limits>
#include <type_traits>

template <typename ValueType = char>
class RGB {
public:
	ValueType r, g, b;

	RGB() : r{}, g{}, b{} {
	}

	template <typename RType, typename GType, typename BType>
	RGB(RType &&r, GType &&g, BType &&b) : r{ValueType(r)}, g{ValueType(g)}, b{ValueType(b)} {
	}
};
