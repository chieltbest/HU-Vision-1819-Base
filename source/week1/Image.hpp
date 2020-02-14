//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_IMAGE_HPP

#include <array>
#include <type_traits>

#include "policy/Null.hpp"

/// An n-dimensional image, consisting of a contiguous array of 'Colour's
template <typename Colour, unsigned... Dimensions>
class Image {
private:
	constexpr static unsigned total_elems = (Dimensions * ... * 1);

	Colour data[total_elems];

	template <unsigned D, unsigned... Ds, typename Num1, typename... Num>
	unsigned calc_index(unsigned mult, Num1 i, Num... ints) {
		return (mult * i) + calc_index<Ds...>(mult * D, ints...);
	}

	template <unsigned... Ds>
	unsigned calc_index(unsigned) {
		return 0;
	}

	template <typename... Ts>
	bool any(Ts... bools) {
		return (false || ... || bools);
	}

public:
	Image() : data{} {
	}

	template <typename ColourT>
	explicit Image(ColourT(&&data)[]) : data{data} {
	}

	template <typename ColourT>
	explicit Image(ColourT(&&data)[total_elems]) : data{data} {
	}

	/// SFINAE-d constructor for std containers with a .data() function
	template <typename Container, typename = decltype(std::declval<Container>().data())>
	explicit Image(Container &&data) : data{data.data()} {};

	template <typename OtherColourType, unsigned... OtherDimensions>
	friend class Image;
	/// convert from other image type
	template <typename OtherColourType>
	explicit Image(Image<OtherColourType, Dimensions...> image) : data{} {
		std::copy(image.data, image.data + total_elems, data);
	}

	template <typename OutOfIndexPolicy, typename... Nums>
	std::enable_if_t<sizeof...(Nums) == sizeof...(Dimensions), Colour &>
	get(OutOfIndexPolicy &&policy, Nums... nums) {
		if (any(((nums < 0) || (unsigned(nums) >= Dimensions))...)) {
			if constexpr (std::is_convertible_v<decltype(policy(nums...)), Colour &>) {
				return policy(nums...);
			} else {
				// if the policy returns void just execute it
				policy(nums...);
			}
		}
		return data[calc_index<Dimensions...>(1, nums...)];
	}
	template <typename... Nums>
	std::enable_if_t<sizeof...(Nums) == sizeof...(Dimensions), Colour &> get(Nums... nums) {
		return get(NullPolicy{}, nums...);
	}
};
