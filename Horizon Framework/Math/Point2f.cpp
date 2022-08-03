#include "Point2f.h"
#include "Vector2f.h"
#include <cmath>
#include <utility>
//Constructors
Math::Point2f::Point2f() noexcept: Point2f(0, 0)
{

}

Math::Point2f::Point2f(float _x, float _y) noexcept:
	x{ _x },
	y{ _y }
{

}

Math::Point2f::Point2f(const Vector2f& vector) noexcept: Point2f(vector.x,vector.y)
{

}

//Copy and move constructor
Math::Point2f::Point2f(Point2f&& other) noexcept:
	x{ std::move(other.x) },
	y{ std::move(other.y) }
{

}

Math::Point2f::Point2f(const Point2f& other) noexcept:
	x{ other.x },
	y{ other.y }
{

}

//Copy and move operator
Math::Point2f& Math::Point2f::operator=(Point2f&& other) noexcept
{
	x = std::move(other.x);
	y = std::move(other.y);
	return *this;
}

Math::Point2f& Math::Point2f::operator=(const Point2f& other) noexcept
{
	x = other.x;
	y = other.y;
	return *this;
}

//Arithmetic operators
Math::Point2f Math::operator+(Point2f lhs, const Vector2f& rhs) noexcept
{
	return Point2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

//Comparison operators
bool Math::operator==(const Math::Point2f& lhs, const Math::Point2f& rhs) noexcept
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool Math::operator!=(const Math::Point2f& lhs, const Math::Point2f& rhs) noexcept
{
	return !(lhs == rhs);
}