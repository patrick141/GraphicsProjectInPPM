#include <cmath>
#include "Vector2.h"

Vector2::Vector2()
{
    x = 0.0;
    y = 0.0;
}

Vector2::Vector2(float a, float b)
{
    x = a;
    y = b;
}

double Vector2::magnitude()
{
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

void Vector2::normalize()
{
    float factor = magnitude();
    x = (1 / factor) * x;
    y = (1 / factor) * y;
}

Vector2 Vector2::operator+(Vector2 b)
{
    Vector2 temp;
    temp.x = x + b.x;
    temp.y = y + b.y;
    return temp;
}

Vector2 Vector2::operator-(Vector2 b)
{
    Vector2 temp;
    temp.x = x - b.x;
    temp.y = y - b.y;
    return temp;
}

Vector2 Vector2::operator*(float b)
{
    Vector2 temp;
    temp.x = x * b;
    temp.y = y * b;
    return temp;
}

double Vector2::dot(Vector2 temp)
{
    return x * temp.x + y * temp.y;
}

Vector2 Vector2::perpendicular()
{
    return Vector2(-y,x);
}