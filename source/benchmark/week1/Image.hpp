//
// Created by chiel on 14-02-20.
//

#pragma once // VISION_IMAGE_BENCHMARK_HPP

#include <chrono>
#include <iostream>

#include <Image.hpp>
#include <colour/Intensity.hpp>
#include <colour/RGB.hpp>

void image_benchmark() {
	using namespace std::chrono_literals;
	using clock = std::chrono::high_resolution_clock;

	constexpr unsigned size = 1000; // width and height of the image

	auto start_time = clock::now();

	Image<RGB<uint8_t>, size, size> image{};

	auto create_time = clock::now() - start_time;
	std::cout << "Time to create Image: " << create_time / 1us << "us" << std::endl;

	// time filling the entire image
	auto fill_start_time = clock::now();

	for (unsigned y = 0; y < size; ++y) {
		for (unsigned x = 0; x < size; ++x) {
			image.get(x, y) = RGB<uint8_t>{uint8_t(x), uint8_t(y), 0};
		}
	}

	auto fill_time = clock::now() - fill_start_time;
	std::cout << "Time to fill Image: " << fill_time / 1us << "us" << std::endl;

	// time converting the image to grayscale
	auto convert_start_time = clock::now();

	Image<Intensity<uint8_t>, size, size>{image};

	auto convert_time = clock::now() - convert_start_time;
	std::cout << "Time to convert Image to grayscale: " << convert_time / 1us << "us" << std::endl;
}
