#pragma once
#ifndef POINT2F_H
#define POINT2F_H

//Warning C4201: nameless struct/union
#pragma warning (push)
#pragma warning (disable: 4201)

namespace Math
{
	struct Vector2f;

	struct Point2f final
	{
		//Constructors
		explicit Point2f() noexcept;
		explicit Point2f(float _x, float _y) noexcept;
		explicit Point2f(const Vector2f& vector) noexcept;

		//Copy and move constructor
		Point2f(Point2f&& other) noexcept;
		Point2f(const Point2f& other) noexcept;

		//Copy and move operator
		Point2f& operator=(Point2f&& other) noexcept;
		Point2f& operator=(const Point2f& other) noexcept;

		//Data members
		union
		{
			struct
			{
				float x, y;
			};
			float data[2];
		};
	};

	//Arithmetic operators
	Point2f operator+(Point2f lhs, const Vector2f& rhs) noexcept;

	//Comparison operators
	bool operator==(const Point2f& lhs, const Point2f& rhs) noexcept;
	bool operator!=(const Point2f& lhs, const Point2f& rhs) noexcept;
}
#pragma warning (pop)
#endif