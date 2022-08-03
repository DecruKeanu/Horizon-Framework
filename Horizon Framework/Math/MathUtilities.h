#pragma once
#include "Vector2f.h"

namespace Math
{
	//Constants
	constexpr float PI = 3.14159265358979323846f;

	constexpr float PI_DIV_2 = PI / 2.f;
	constexpr float PI_DIV_4 = PI / 4.f;

	constexpr float PI_MUL_2 = PI * 2.f;
	constexpr float PI_MUL_4 = PI * 4.f;

	constexpr float TO_DEGREES = 180.f / PI;
	constexpr float TO_RADIANS = PI / 180.f;

	//Functions
	template <typename T>
	T Square(T value);

	float ToRadians(float degrees);
	float ToDegrees(float radians);

	bool Equal(const float lhs, const float rhs);
	float FLerp(const float startValue, const float endValue, float lerpValue);

}

template<typename T>
T Math::Square(T value)
{
	return (value * value);
}