//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_IMAGE_HPP

#include <array>
#include <type_traits>

/// An n-dimensional image, consisting of a contiguous array of 'Colour's
template <typename Colour, unsigned BaseDimension, unsigned... Dimensions>
class Image {
private:
	constexpr static unsigned total_elems = BaseDimension * (Dimensions * ... * 1);

	Colour data[total_elems];

	template <unsigned D, unsigned... Ds, typename Num1, typename... Num>
	unsigned calc_index(unsigned mult, Num1 i, Num... ints) {
		return (mult * i) + calc_index<Ds...>(mult * D, ints...);
	}

	template <unsigned... Ds>
	unsigned calc_index(unsigned mult) {
		return 0;
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

	/// convert from other image type
	template <typename OtherColourType, unsigned... OtherDimensions>
	explicit Image(Image<OtherColourType, OtherDimensions...> &&image) : Image(image.data) {
	}

	template <typename... Nums>
	std::enable_if_t<sizeof...(Nums) == sizeof...(Dimensions) + 1, Colour &> get(Nums... nums) {
		return data[calc_index<BaseDimension, Dimensions...>(1, nums...)];
	}
};
