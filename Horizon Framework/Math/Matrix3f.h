#pragma once
#ifndef MATRIXF_H
#define MATRIXF_H

//Warning C4201: nameless struct/union
#pragma warning (push)
#pragma warning (disable: 4201)

namespace Math
{
	struct Point2f;

	struct Matrix3f
	{
		//Constructors
		Matrix3f();
		Matrix3f(const float _00, const float _01, const float _02, const float _10, const float _11, const float _12, const float _20, const float _21, const float _22);

		//Copy and move constructor
		Matrix3f(Matrix3f&& other) noexcept;
		Matrix3f(const Matrix3f& other) noexcept;

		//Copy and move operator
		Matrix3f& operator=(Matrix3f&& other) noexcept;
		Matrix3f& operator=(const Matrix3f& other) noexcept;

		//Data members
		float data[3][3];
	};

	//Arithmetic operators
	Matrix3f operator+(Matrix3f lhs, const Matrix3f& rhs) noexcept;
	Matrix3f operator-(Matrix3f lhs, const Matrix3f& rhs) noexcept;
	Matrix3f operator*(Matrix3f lhs, const Matrix3f& rhs) noexcept;
	Matrix3f operator*(Matrix3f lhs, const float value) noexcept;
	Matrix3f operator/(Matrix3f lhs, const Matrix3f& rhs) noexcept;
	Matrix3f operator/(Matrix3f lhs, const float value) noexcept;

	//Compound assignment operators
	Matrix3f& operator+=(Matrix3f& lhs, const Matrix3f& rhs) noexcept;
	Matrix3f& operator-=(Matrix3f& lhs, const Matrix3f& rhs) noexcept;
	Matrix3f& operator*=(Matrix3f& lhs, const Matrix3f& rhs) noexcept;
	Matrix3f& operator*=(Matrix3f& lhs, const float value) noexcept;
	Matrix3f& operator/=(Matrix3f& lhs, const Matrix3f& rhs) noexcept;
	Matrix3f& operator/=(Matrix3f& lhs, const float value) noexcept;

	//Comparison operators
	bool operator==(const Matrix3f& lhs, const Matrix3f& rhs) noexcept;
	bool operator!=(const Matrix3f& lhs, const Matrix3f& rhs) noexcept;

	//Functions
	Matrix3f MakeIdentityMatrix();
	Matrix3f MakeTranslationMatrix(const Point2f& translation);
	Matrix3f MakeRotationMatrix(float degrees);
	Matrix3f MakeScaleMatrix(const Point2f& scale);
	Matrix3f MakeTRSMatrix(const Point2f& translation, float degrees, const Point2f& scale);
	Matrix3f MakeTransposedMatrix(const Matrix3f& matrix);
	float Determinant(const Matrix3f& matrix);
}
#pragma warning (pop)
#endif