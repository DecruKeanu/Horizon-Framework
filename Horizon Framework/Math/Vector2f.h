#pragma once
#ifndef VECTOR2F_H
#define VECTOR2F_H

//Warning C4201: nameless struct/union
#pragma warning (push)
#pragma warning (disable: 4201)

namespace Math
{
	struct Point2f;

	struct Vector2f final
	{
		//Constructors
		Vector2f() noexcept;
		Vector2f(float _x, float _y) noexcept;
		Vector2f(const Point2f& point) noexcept;

		//Copy and move constructor
		Vector2f(Vector2f&& other) noexcept;
		Vector2f(const Vector2f& other) noexcept;

		//Copy and move operators
		Vector2f& operator=(Vector2f&& other) noexcept;
		Vector2f& operator=(const Vector2f& other) noexcept;

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
	Vector2f operator+(Vector2f lhs, const Vector2f& rhs) noexcept;

	Vector2f operator-(const Point2f& lhs, const Point2f& rhs) noexcept;
	Vector2f operator-(Vector2f lhs, const Vector2f& rhs) noexcept;

	Vector2f operator/(Vector2f lhs, const Vector2f& rhs) noexcept;
	Vector2f operator/(Vector2f lhs, const float value) noexcept;

	Vector2f operator*(Vector2f lhs, const Vector2f& rhs) noexcept;
	Vector2f operator*(Vector2f lhs, const float value) noexcept;

	//Compound assigment operators
	Vector2f& operator+=(Vector2f& lhs, const Vector2f& rhs) noexcept;
	Vector2f& operator-=(Vector2f& lhs, const Vector2f& rhs) noexcept;
	Vector2f& operator*=(Vector2f& lhs, const Vector2f& rhs) noexcept;
	Vector2f& operator*=(Vector2f& lhs, const float rhs) noexcept;
	Vector2f& operator/=(Vector2f& lhs, const Vector2f& rhs) noexcept;
	Vector2f& operator/=(Vector2f& lhs, const float rhs) noexcept;

	//Comparison operators
	bool operator==(const Vector2f& lhs, const Vector2f& rhs) noexcept;
	bool operator!=(const Vector2f& lhs, const Vector2f& rhs) noexcept;

	//Functions
	Vector2f Normalize(const Vector2f& vector) noexcept;

	float Magnitude(const Vector2f& vector) noexcept;
	float SquaredMagnitude(const Vector2f& vector) noexcept;
	float Dot(const Vector2f& v1, const Vector2f& v2) noexcept;
	float Cross(const Vector2f& v1, const Vector2f& v2) noexcept;
}
#pragma warning (pop)
#endif