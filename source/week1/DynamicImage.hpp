//
// Created by chiel on 20-02-20.
//

#pragma once // VISION_DYNAMICIMAGE_HPP

#include <memory>

#include "../ExternalDLL/ExternalDLL/Image.h"

#include "policy/Null.hpp"

/// shared dynamic Image implementation for Intensity and RGB Image classes
template <typename ColourType, typename Base, typename Policy = void>
class DynamicImage : public Base {
private:
	std::unique_ptr<ColourType[]> data;

	unsigned total_elems() {
		return Base::getWidth() * Base::getHeight();
	}

public:
	DynamicImage() : data{} {
	}
	/// copy constructor
	DynamicImage(const DynamicImage<ColourType, Base, Policy> &other)
	    : Base{other.getWidth(), other.getHeight()},
	      data{new ColourType[other.getWidth() * other.getHeight()]} {
		std::copy(other.data.get(), other.data.get() + total_elems(), data.get());
	}
	DynamicImage(const int width, const int height)
	    : Base{width, height}, data{new ColourType[width * height]} {
	}
	~DynamicImage() override = default;

	void set(const int width, const int height) override {
		Base::set(width, height);
		data = std::make_unique<ColourType[]>(width * height);
	}
	void set(const DynamicImage<ColourType, Base, Policy> &other) {
		set(other.getWidth(), other.getHeight());
		std::copy(other.data.get(), other.data.get() + total_elems(), data.get());
	}

	void setPixel(int x, int y, ColourType pixel) override {
		if constexpr (!std::is_same_v<Policy, void>) {
			if (x >= Base::getWidth() || y >= Base::getHeight()) {
				Policy{}(x, y, Base::getWidth(), Base::getHeight());
			}
		}
		data[x + y * Base::getWidth()] = pixel;
	}
	void setPixel(int i, ColourType pixel) override {
		if constexpr (!std::is_same_v<Policy, void>) {
			if (i >= total_elems()) {
				Policy{}(i, total_elems());
			}
		}
		data[i] = pixel;
	}

	ColourType getPixel(int x, int y) const override {
		return data[x + y * Base::getWidth()];
	}
	ColourType getPixel(int i) const override {
		return data[i];
	}
};
