#pragma once
#include <math.h>
#include "GraphicsEngine/Math.h"


class Vector3
{
public:
	double x, y, z;

public:

	Vector3()
	: x(0), y(0), z(0)
	{

	}

	Vector3(double x, double y, double z)
	: x(x), y(y), z(z)
	{

	}

	Vector3(const Vector3 & vec)
	: x(vec.x), y(vec.y), z(vec.z)
	{

	}

	const Vector3 & operator - ()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;

		return *this;
	}

	const Vector3 & operator += (const Vector3 & vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;

		return *this;
	}

	const Vector3 & operator -= (const Vector3 & vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;

		return *this;
	}

	const Vector3 & operator *= (const double k)
	{
		this->x *= k;
		this->y *= k;
		this->z *= k;

		return *this;
	}

	Vector3 & Normalize()
	{
		double length = sqrt(x*x + y*y + z*z);

		*this *= (1.0 / length);

		return *this;
	}

	double Norma()
	{
		double length = sqrt(x*x + y*y + z*z);

		return length;
	}

    static double Dot(const Vector3 & a, const Vector3 & b)
	{
        double result = a.x * b.x + a.y * b.y + a.z * b.z;

		return result;
	}

	static Vector3 Cross(const Vector3 & a, const Vector3 & b)
	{
		Vector3 result;

		result.x = a.y * b.z - a.z * b.y;
		result.y = -(a.x * b.z - a.z * b.x);
		result.z = a.x * b.y - a.y * b.x;

		return result;
	}

	/**
	* @brief Clamps vector coordinates by interval [0,1].
	*/
	static Vector3 Clamp01(const Vector3 & a)
	{
		Vector3 result;

		result.x = Math::Clamp(a.x, 0.0, 1.0);
		result.y = Math::Clamp(a.y, 0.0, 1.0);
		result.z = Math::Clamp(a.z, 0.0, 1.0);

		return result;
	}
};

Vector3 operator + (const Vector3 & vec1, const Vector3 & vec2);
Vector3 operator - (const Vector3 & vec1, const Vector3 & vec2);
Vector3 operator * (const Vector3 & vec, const double k);
Vector3 operator * (const double k, const Vector3 & vec);
