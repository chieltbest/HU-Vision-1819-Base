//
// Created by chiel on 11-02-20.
//

#pragma once // VISION_IMAGE_HPP

#include <iostream>
#include <Image.hpp>
#include <colour/Intensity.hpp>
#include <colour/RGB.hpp>

bool test_image() {
	// construct the image object
	Image<RGB<uint8_t>, 10, 10> image{};
	image.get(1, 2)               = {255, 0, 0};
	image.get(NullPolicy{}, 2, 2) = {0, 255, 0};

	Image<Intensity<uint8_t>, 10, 10> grayscale{image};

	for (int y = 0; y < 10; ++y) {
		for (int x = 0; x < 10; ++x) {
			std::cout << int(grayscale.get(x, y).value) << "\t";
		}
		std::cout << "\n";
	}
	std::cout.flush();

	return true;
}
