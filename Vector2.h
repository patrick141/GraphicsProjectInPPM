#ifndef Vector2_H
#define Vector2_H
#include <cmath>

struct Vector2
{
    float x;
    float y; 

    Vector2();
    Vector2(float a, float b);
    Vector2 operator*(float a);
    Vector2 operator+(Vector2 x);
    Vector2 operator-(Vector2 x);
    double magnitude();
    double dot(Vector2 temp);
    void normalize();
    Vector2 perpendicular();
    void translate(float x, float y);
    void rotate(float angle);
    void scale(float a, float b);
};

float determinant(Vector2 a, Vector2 b);

#endif