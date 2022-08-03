#pragma once
#ifndef CIRCLEF_H
#define CIRCLEF_H

#include "Point2f.h"

namespace Math
{
	struct Circlef
	{
		//Constructors
		Circlef() noexcept;
		Circlef(const Point2f& _center, float _radius) noexcept;

		//Copy and move constructor
		Circlef(Circlef&& other) noexcept;
		Circlef(const Circlef& other) noexcept;

		//Copy and move operator
		Circlef& operator=(Circlef&& other) noexcept;
		Circlef& operator=(const Circlef& other) noexcept;

		//Data members
		Point2f center;
		float radius;
	};

	//Functions
	bool IsPointInCircle(const Circlef& circle, const Point2f& point) noexcept;
	bool DoesCircleOverlapWithCircle(const Circlef& firstCircle, const Circlef& secondCircle) noexcept;
}



#endif