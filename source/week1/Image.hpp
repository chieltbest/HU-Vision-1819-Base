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
};
