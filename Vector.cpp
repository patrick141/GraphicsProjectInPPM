#include "Vector.h"

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

//determinant function
float determinant(Vector2 a, Vector2 b)
{
    return b.x*a.y - b.y*a.x;
}

void Vector2::translate(float a, float b)
{
    x += a;
    y += b;
}

void Vector2::rotate(float angle)
{
    float a = x;
    float b = y;
    float cosF = cos(angle * M_PI / 180.0);
    float sinF = sin(angle * M_PI / 180.0);

    x = a * cosF - b * sinF;
    y = a * sinF + b * cosF;
}

void Vector2::scale(float a, float b)
{
    x *= a;
    y *= b;
}

//Vector4

Vector4::Vector4()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
    w = 0.0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW)
{
    x = pX;
    y = pY;
    z = pZ;
    w = pW;
}

double Vector4::magnitude()
{
    return sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z,2.0) + pow(w,2.0));
}

void Vector4::normalize()
{
    float factor = magnitude();
    x = (1 / factor) * x;
    y = (1 / factor) * y;
    z = (1 / factor) * z;
    w = (1 / factor) * w;
}

Vector4 Vector4::operator+(Vector4 b)
{
    Vector4 temp;
    temp.x = x + b.x;
    temp.y = y + b.y;
    temp.z = z + b.z;
    temp.w = w + b.w;
    return temp;
}

Vector4 Vector4::operator-(Vector4 b)
{
    Vector4 temp;
    temp.x = x - b.x;
    temp.y = y - b.y;
    temp.z = z - b.z;
    temp.w = w - b.w;
    return temp;
}

Vector4 Vector4::operator*(float b)
{
    Vector4 temp;
    temp.x = x * b;
    temp.y = y * b;
    temp.z = z * b;
    temp.w = w * b;
    return temp;
}

double Vector4::dot(Vector4 temp)
{
    return x * temp.x + y * temp.y + z * temp.z + w * temp.w;
}

void Vector4::translate(float a, float b)
{
    x += a;
    y += b;
}

void Vector4::rotate(float angle)
{
    float a = x;
    float b = y;
    float cosF = cos(angle * M_PI / 180.0);
    float sinF = sin(angle * M_PI / 180.0);

    x = a * cosF - b * sinF;
    y = a * sinF + b * cosF;
}

void Vector4::scale(float a, float b)
{
    x *= a;
    y *= b;
}

void Vector4::print()
{
    std::cout << x << ", " << y << ", " <<  z << ", " <<  w << std::endl;
}