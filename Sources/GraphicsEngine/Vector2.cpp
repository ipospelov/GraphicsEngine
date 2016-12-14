#include "GraphicsEngine/Vector2.h"


Vector2 operator + (const Vector2 & vec1, const Vector2 & vec2)
{
    Vector2 result(vec1);

    result += vec2;

    return result;
}

Vector2 operator - (const Vector2 & vec1, const Vector2 & vec2)
{
    Vector2 result(vec1);

    result -= vec2;

    return result;
}

Vector2 operator * (const Vector2 & vec, const double k)
{
    Vector2 result(vec);

    result *= k;

    return result;
}

Vector2 operator * (const double k, const Vector2 & vec)
{
    Vector2 result(vec * k);

    return result;
}
