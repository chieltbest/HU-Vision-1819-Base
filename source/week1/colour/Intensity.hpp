//
// Created by chiel on 12-02-20.
//

#pragma once // VISION_GRAYSCALE_HPP

template <typename ValueType>
class Intensity {
public:
	ValueType value;

	template <typename VType>
	Intensity(VType &&value) : value{value} {
	}
};
