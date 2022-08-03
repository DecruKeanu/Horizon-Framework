#include "Vector2f.h"
#include "Point2f.h"
#include <cmath>

//Constructors
Math::Vector2f::Vector2f() noexcept : Vector2f(0, 0)
{

}

Math::Vector2f::Vector2f(float _x, float _y) noexcept:
	x{_x},
	y{_y}
{

}

Math::Vector2f::Vector2f(const Point2f& point) noexcept : Vector2f(point.x,point.y)
{

}

//Copy and move constructor
Math::Vector2f::Vector2f(Vector2f&& other) noexcept : Vector2f(other.x,other.y)
{

}

Math::Vector2f::Vector2f(const Vector2f& other) noexcept :
	x{ other.x },
	y{ other.y }
{

}

//Copy and move operators
Math::Vector2f& Math::Vector2f::operator=(Vector2f&& other) noexcept
{
	x = other.x;
	y = other.y;

	return *this;
}

Math::Vector2f& Math::Vector2f::operator=(const Vector2f& other) noexcept
{
	x = other.x;
	y = other.y;
	return *this;
}

//Arithmetic operators
Math::Vector2f Math::operator+(Math::Vector2f lhs, const Math::Vector2f& rhs) noexcept
{
	return (lhs += rhs);
}

Math::Vector2f Math::operator-(const Point2f& lhs, const Point2f& rhs) noexcept
{
	return Vector2f(lhs.x - rhs.x, rhs.y - lhs.y);
}

Math::Vector2f Math::operator-(Math::Vector2f lhs, const Math::Vector2f& rhs) noexcept
{
	return (lhs -= rhs);
}

Math::Vector2f Math::operator*(Math::Vector2f lhs, const Math::Vector2f& rhs) noexcept
{
	return (lhs *= rhs);
}

Math::Vector2f Math::operator*(Math::Vector2f lhs, const float value) noexcept
{
	return lhs *= Math::Vector2f{ value, value };
}

Math::Vector2f Math::operator/(Math::Vector2f lhs, const Math::Vector2f& rhs) noexcept
{
	return (lhs /= rhs);
}

Math::Vector2f Math::operator/(Math::Vector2f lhs, const float value) noexcept
{
	return lhs /= Math::Vector2f{ value, value };
}

//Compound assigment operators
Math::Vector2f& Math::operator+=(Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

Math::Vector2f& Math::operator-=(Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

Math::Vector2f& Math::operator*=(Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;

	return lhs;
}

Math::Vector2f& Math::operator*=(Vector2f& lhs, const float rhs) noexcept
{
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}

Math::Vector2f& Math::operator/=(Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;

	return lhs;
}

Math::Vector2f& Math::operator/=(Vector2f& lhs, const float rhs) noexcept
{
	lhs.x /= rhs;
	lhs.y /= rhs;

	return lhs;
}

//Comparison operators
bool Math::operator==(const Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	return (lhs.x == rhs.x && rhs.y == rhs.y);
}

bool Math::operator!=(const Math::Vector2f& lhs, const Math::Vector2f& rhs) noexcept
{
	return !(lhs == rhs);
}

//Functions
Math::Vector2f Math::Normalize(const Vector2f& vector) noexcept
{
	const float magnitude = Magnitude(vector);
	return Vector2f(vector.x / magnitude, vector.y / magnitude);
}

float Math::Magnitude(const Vector2f& vector) noexcept
{
	return std::sqrt(SquaredMagnitude(vector));
}

float Math::SquaredMagnitude(const Vector2f& vector) noexcept
{
	return (vector.x * vector.x + vector.y * vector.y);
}

float Math::Dot(const Vector2f& v1, const Vector2f& v2) noexcept
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float Math::Cross(const Vector2f& v1, const Vector2f& v2) noexcept
{
	return (v1.x * v2.y - v1.y * v2.x);
}