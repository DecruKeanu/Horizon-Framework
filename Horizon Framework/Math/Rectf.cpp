#include "Rectf.h"
#include <utility>
//Constructors
Math::Rectf::Rectf() noexcept : Rectf(0.f,0.f)
{
}

Math::Rectf::Rectf(float width, float height) noexcept : 
	leftBottom{0,0},
	size{width, height}
{

}

Math::Rectf::Rectf(const Point2f& leftBottom, float width, float height) noexcept :
	leftBottom{ leftBottom },
	size{ width, height }
{

}

Math::Rectf::Rectf(const Point2f& _leftBottom, const Vector2f& _size) noexcept : Rectf(_leftBottom,_size.x,_size.y)
{

}

////Copy and move constructor
Math::Rectf::Rectf(Rectf&& other) noexcept : Rectf(std::move(other.leftBottom),std::move(other.size))
{

}

Math::Rectf::Rectf(const Rectf& other) noexcept : Rectf(other.leftBottom, other.size)
{
}

//Copy and move operator
Math::Rectf& Math::Rectf::operator=(Rectf&& other) noexcept
{
	leftBottom = std::move(other.leftBottom);
	size = std::move(other.size);

	return *this;
}

Math::Rectf& Math::Rectf::operator=(const Rectf& other) noexcept
{
	leftBottom = other.leftBottom;
	size = other.size;

	return *this;
}

//Functions
bool Math::IsPointInRect(const Rectf& rect, const Point2f& point) noexcept
{
	//check if point is right of rect 
	if (point.x > rect.leftBottom.x + rect.size.x)
		return false;

	//check if point is left of rect 
	if (point.x < rect.leftBottom.x)
		return false;

	//check if point is below rect 
	if (point.y < rect.leftBottom.y)
		return false;

	//check if point is above rect 
	if (point.y > rect.leftBottom.y + rect.size.y)
		return false;

	return true;
}

bool Math::DoesRectOverlapWithRect(const Rectf& firstRect, const Rectf& secondRect) noexcept
{
	//check if secondRect is right of firstRect 
	if (firstRect.leftBottom.x + firstRect.size.x < secondRect.leftBottom.x)
		return false;

	//check if secondRect is left of firstRect 
	if (firstRect.leftBottom.x > secondRect.leftBottom.x + secondRect.size.x)
		return false;

	//check if secondRect is below firstRect 
	if (firstRect.leftBottom.y > secondRect.leftBottom.y + secondRect.size.y)
		return false;

	//check if secondRect is above firstRect 
	if (firstRect.leftBottom.y + firstRect.size.y < secondRect.leftBottom.y)
		return false;

	return true;
}
