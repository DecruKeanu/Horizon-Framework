#pragma once
#ifndef RECTF_H
#define RECTF_H

#include "Point2f.h"
#include "Vector2f.h"

namespace Math
{
	struct Rectf
	{
		//Constructors
		Rectf() noexcept;
		Rectf(float width, float height) noexcept;
		Rectf(const Point2f& _leftBottom, float width, float height) noexcept;
		Rectf(const Point2f& _leftBottom, const Vector2f& _size) noexcept;

		//Copy and move constructor
		Rectf(Rectf&& other) noexcept;
		Rectf(const Rectf& other) noexcept;

		//Copy and move operator
		Rectf& operator=(Rectf&& other) noexcept;
		Rectf& operator=(const Rectf& other) noexcept;

		//Data members
		Point2f leftBottom;
		Vector2f size;
	};

	//Functions
	bool IsPointInRect(const Rectf& rect, const Point2f& point) noexcept;
	bool DoesRectOverlapWithRect(const Rectf& firstRect, const Rectf& secondRect) noexcept;
}
#endif
