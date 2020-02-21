//
// Created by chiel on 21-02-20.
//

#pragma once // VISION_THROWPOLICY_HPP

template <typename ExceptionType>
class ThrowPolicy {
public:
	template <typename... Ts>
	void operator()(Ts &&...) {
		throw ExceptionType{"exception"};
	}
};
