#include "Matrix3f.h"
#include "Point2f.h"
#include "MathUtilities.h"
#include <cmath>
#include <utility>

//Constructors
Math::Matrix3f::Matrix3f() :
	data{}
{

}

Math::Matrix3f::Matrix3f(const float _00, const float _01, const float _02, const float _10, const float _11, const float _12, const float _20, const float _21, const float _22)
{
	data[0][0] = _00;
	data[0][1] = _01;
	data[0][2] = _02;
	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;
	data[2][0] = _20;
	data[2][1] = _21;
	data[2][2] = _22;
}

//Copy and move constructor
Math::Matrix3f::Matrix3f(Matrix3f&& other) noexcept : Matrix3f(std::move(other.data[0][0]), std::move(other.data[0][1]), std::move(other.data[0][2]), std::move(other.data[1][0]), std::move(other.data[1][1]), std::move(other.data[1][2])
	, std::move(other.data[2][0]), std::move(other.data[2][1]), std::move(other.data[2][2]))
{

}

Math::Matrix3f::Matrix3f(const Matrix3f& other) noexcept : Matrix3f(other.data[0][0], other.data[0][1], other.data[0][2], other.data[1][0], other.data[1][1], other.data[1][2], other.data[2][0], other.data[2][1], other.data[2][2])
{

}

//Copy and move operator
Math::Matrix3f& Math::Matrix3f::operator=(Matrix3f&& other) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			data[row][collumn] = std::move(other.data[row][collumn]);

	return *this;
}

Math::Matrix3f& Math::Matrix3f::operator=(const Matrix3f& other) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			data[row][collumn] = other.data[row][collumn];

	return *this;
}

//Arithmetic operators
Math::Matrix3f Math::operator+(Matrix3f lhs, const Matrix3f& rhs) noexcept
{
	return (lhs += rhs);
}

Math::Matrix3f Math::operator-(Matrix3f lhs, const Matrix3f& rhs) noexcept
{
	return (lhs -= rhs);
}

Math::Matrix3f Math::operator*(Matrix3f lhs, const Matrix3f& rhs) noexcept
{
	return Matrix3f(
		lhs.data[0][0] * rhs.data[0][0] + lhs.data[0][1] * rhs.data[1][0] + lhs.data[0][2] * rhs.data[2][0],
		lhs.data[0][0] * rhs.data[0][1] + lhs.data[0][1] * rhs.data[1][1] + lhs.data[0][2] * rhs.data[2][1],
		lhs.data[0][0] * rhs.data[0][2] + lhs.data[0][1] * rhs.data[1][2] + lhs.data[0][2] * rhs.data[2][2],

		lhs.data[1][0] * rhs.data[0][0] + lhs.data[1][1] * rhs.data[1][0] + lhs.data[1][2] * rhs.data[2][0],
		lhs.data[1][0] * rhs.data[0][1] + lhs.data[1][1] * rhs.data[1][1] + lhs.data[1][2] * rhs.data[2][1],
		lhs.data[1][0] * rhs.data[0][2] + lhs.data[1][1] * rhs.data[1][2] + lhs.data[1][2] * rhs.data[2][2],

		lhs.data[2][0] * rhs.data[0][0] + lhs.data[2][1] * rhs.data[1][0] + lhs.data[2][2] * rhs.data[2][0],
		lhs.data[2][0] * rhs.data[0][1] + lhs.data[2][1] * rhs.data[1][1] + lhs.data[2][2] * rhs.data[2][1],
		lhs.data[2][0] * rhs.data[0][2] + lhs.data[2][1] * rhs.data[1][2] + lhs.data[2][2] * rhs.data[2][2]);
}

Math::Matrix3f Math::operator*(Matrix3f lhs, const float value) noexcept
{
	return (lhs *= value);
}

Math::Matrix3f Math::operator/(Matrix3f lhs, const Matrix3f& rhs) noexcept
{
	return (lhs /= rhs);
}

Math::Matrix3f Math::operator/(Matrix3f lhs, const float value) noexcept
{
	return (lhs /= value);
}

//Compound assignment operators
Math::Matrix3f& Math::operator+=(Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			lhs.data[row][collumn] += rhs.data[row][collumn];

	return lhs;
}

Math::Matrix3f& Math::operator-=(Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			lhs.data[row][collumn] -= rhs.data[row][collumn];

	return lhs;
}

Math::Matrix3f& Math::operator*=(Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	lhs = lhs * rhs;
	return lhs;
}

Math::Matrix3f& Math::operator*=(Matrix3f& lhs, const float value) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			lhs.data[row][collumn] *= value;

	return lhs;
}

Math::Matrix3f& Math::operator/=(Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			lhs.data[row][collumn] /= rhs.data[row][collumn];

	return lhs;
}

Math::Matrix3f& Math::operator/=(Matrix3f& lhs, const float value) noexcept
{
	for (int row = 0; row < 3; row++)
		for (int collumn = 0; collumn < 3; collumn++)
			lhs.data[row][collumn] /= value;

	return lhs;
}

bool Math::operator==(const Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			if (!Math::Equal(lhs.data[row][collumn], rhs.data[row][collumn]))
				return false;
		}
	}

	return true;
}

bool Math::operator!=(const Matrix3f& lhs, const Matrix3f& rhs) noexcept
{
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			if (Math::Equal(lhs.data[row][collumn], rhs.data[row][collumn]))
				return false;
		}
	}

	return true;
}

//Functions
Math::Matrix3f Math::MakeIdentityMatrix()
{
	return Matrix3f(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);
}

Math::Matrix3f Math::MakeTranslationMatrix(const Point2f& translation)
{
	return Matrix3f(1.f, 0.f, translation.x, 0.f, 1.f, translation.y, 0.f, 0.f, 1.f);
}

Math::Matrix3f Math::MakeRotationMatrix(float degrees)
{
	return Matrix3f(std::cos(degrees), -std::sin(degrees), 0.f, std::sin(degrees), std::cos(degrees), 0.f, 0.f, 0.f, 1.f);
}

Math::Matrix3f Math::MakeScaleMatrix(const Point2f& scale)
{
	return Matrix3f(scale.x, 0.f, 0.f, 0.f, scale.y, 0.f, 0.f, 0.f, 1.f);
}

Math::Matrix3f Math::MakeTRSMatrix(const Point2f& translation, float degrees, const Point2f& scale)
{
	return MakeTranslationMatrix(translation) * MakeRotationMatrix(degrees) * MakeScaleMatrix(scale);
}

Math::Matrix3f Math::MakeTransposedMatrix(const Matrix3f& matrix)
{
	Matrix3f transposedMatrix{};
	transposedMatrix.data[0][0] = matrix.data[0][0];
	transposedMatrix.data[0][1] = matrix.data[1][0];
	transposedMatrix.data[0][2] = matrix.data[2][0];
	transposedMatrix.data[1][0] = matrix.data[0][1];
	transposedMatrix.data[1][1] = matrix.data[1][1];
	transposedMatrix.data[1][2] = matrix.data[2][1];
	transposedMatrix.data[2][0] = matrix.data[0][2];
	transposedMatrix.data[2][1] = matrix.data[1][2];
	transposedMatrix.data[2][2] = matrix.data[2][2];
	return transposedMatrix;
}

//Functions
float Math::Determinant(const Matrix3f& matrix)
{
	return
		+matrix.data[0][0] * (matrix.data[1][1] * matrix.data[2][2] - matrix.data[1][2] * matrix.data[2][1])
		- matrix.data[0][1] * (matrix.data[1][0] * matrix.data[2][2] - matrix.data[1][2] * matrix.data[2][0])
		+ matrix.data[0][2] * (matrix.data[1][0] * matrix.data[2][1] - matrix.data[1][1] * matrix.data[2][0]);
}



