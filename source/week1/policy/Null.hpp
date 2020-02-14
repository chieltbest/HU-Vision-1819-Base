//
// Created by chiel on 13-02-20.
//

#pragma once // VISION_NULL_HPP

class NullPolicy {
public:
	template <typename... Ts>
	void operator()(Ts &&...) {
	}
};
