#include "MathUtilities.h"
#include <cmath>
#include <limits>

float Math::ToRadians(float degrees)
{
	return (degrees * TO_RADIANS);
}

float Math::ToDegrees(float radians)
{
	return (radians * TO_DEGREES);
}


bool Math::Equal(const float lhs, const float rhs)
{
	const float precision = std::numeric_limits<float>::epsilon() * std::fmax(std::fabs(lhs), std::fabs(rhs));
	return (std::fabs(lhs - rhs) <= precision);
}

float Math::FLerp(const float startValue, const float endValue, float lerpValue)
{
	//returns a value between startValue and endValue at the hand of the lerpValue
	return (startValue + (endValue - startValue) * lerpValue);
}
