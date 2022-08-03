#include "Circlef.h"
#include "MathUtilities.h"
#include <cmath>
#include <utility>

//Constructors
Math::Circlef::Circlef() noexcept : Circlef{ Math::Point2f{}, 0.f }
{

}

Math::Circlef::Circlef(const Point2f& _center, float _radius) noexcept :
	center{ _center },
	radius{ _radius }
{

}

////Copy and move constructor
Math::Circlef::Circlef(Circlef&& other) noexcept : 
	center{std::move(other.center)},
	radius{std::move(other.radius)}
{

}

Math::Circlef::Circlef(const Circlef& other) noexcept :
	center{other.center},
	radius{other.radius}
{

}

//Copy and move operator
Math::Circlef& Math::Circlef::operator=(Circlef&& other) noexcept
{
	center = std::move(other.center);
	radius = std::move(other.radius);
	return *this;
}

Math::Circlef& Math::Circlef::operator=(const Circlef& other) noexcept
{
	center = other.center;
	radius = other.radius;
	return *this;
}

//Functions
bool Math::IsPointInCircle(const Circlef& circle, const Point2f& point) noexcept
{
	return Math::Square(point.x - circle.center.x) + Math::Square(point.y - circle.center.y) <= Math::Square(circle.radius);
}

bool Math::DoesCircleOverlapWithCircle(const Circlef& firstCircle, const Circlef& secondCircle) noexcept
{
	const float distanceSquared = Math::Square(firstCircle.center.x - secondCircle.center.x) + Math::Square(firstCircle.center.y - secondCircle.center.y);
	const float radiusSumSquared = Math::Square(firstCircle.radius + secondCircle.radius);

	if (distanceSquared > radiusSumSquared)
		return false;

	return true;
}
