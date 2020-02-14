//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_IMAGE_HPP

#include <Image.hpp>

bool test_image() {
	// construct the image object
	Image<char, 10, 10> image{};
	image.get(1, 2)               = 1;
	image.get(NullPolicy{}, 2, 2) = 1;
	return true;
}
