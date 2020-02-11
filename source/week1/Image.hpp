//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_IMAGE_HPP

/// An n-dimensional image, consisting of a contiguous array of 'Colour's
template <typename Colour, unsigned... Dimensions>
class Image {
private:
	constexpr static total_elems = Dimensions * ...;

	Colour data[total_elems];

public:
	Image() : data{} {
	}

	template <typename Colour>
	Image(Colour &&data[]) : data{data} {
	}

	Image(Colour &&data[total_elems]) : data{data} {
	}

	template <typename Container>
	Image(Container &&data) : data{data} {
	}
};
