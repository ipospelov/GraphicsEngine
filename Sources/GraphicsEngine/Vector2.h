#pragma once
#include <math.h>
#include "GraphicsEngine/Math.h"


class Vector2
{
public:
    double x, y;

public:

    Vector2()
            : x(0), y(0)
    {

    }

    Vector2(double x, double y)
            : x(x), y(y)
    {

    }

    Vector2(const Vector2 & vec)
            : x(vec.x), y(vec.y)
    {

    }

    const Vector2 & operator - ()
    {
        this->x = -this->x;
        this->y = -this->y;

        return *this;
    }

    const Vector2 & operator += (const Vector2 & vec)
    {
        this->x += vec.x;
        this->y += vec.y;

        return *this;
    }

    const Vector2 & operator -= (const Vector2 & vec)
    {
        this->x -= vec.x;
        this->y -= vec.y;

        return *this;
    }

    const Vector2 & operator *= (const double k)
    {
        this->x *= k;
        this->y *= k;

        return *this;
    }

    Vector2 & Normalize()
    {
        double length = sqrt(x*x + y*y);

        *this *= (1.0 / length);

        return *this;
    }

    double Norma()
    {
        double length = sqrt(x*x + y*y);

        return length;
    }

    static double Dot(const Vector2 & a, const Vector2 & b)
    {
        double result = a.x * b.x + a.y * b.y;

        return result;
    }

    static Vector2 Cross(const Vector2 & a, const Vector2 & b)
    {
        Vector2 result;

        result.x = a.y * b.x - a.x * b.y;
        result.y = -(a.x * b.y - a.y * b.x);

        return result;
    }

    /**
    * @brief Clamps vector coordinates by interval [0,1].
    */
    static Vector2 Clamp01(const Vector2 & a)
    {
        Vector2 result;

        result.x = Math::Clamp(a.x, 0.0, 1.0);
        result.y = Math::Clamp(a.y, 0.0, 1.0);
        return result;
    }
};

Vector2 operator + (const Vector2 & vec1, const Vector2 & vec2);
Vector2 operator - (const Vector2 & vec1, const Vector2 & vec2);
Vector2 operator * (const Vector2 & vec, const double k);
Vector2 operator * (const double k, const Vector2 & vec);
