#ifndef Vector_H
#define Vector_H
#include <cmath>
#include <iostream>

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

struct Vector4 {
    float x;
    float y;
    float z;
    float w;

    Vector4();
    Vector4(float pX, float pY, float pZ, float pW);
    Vector4 operator*(float a);
    Vector4 operator+(Vector4 x);
    Vector4 operator-(Vector4 x);
    double magnitude();
    double dot(Vector4 temp);
    void normalize();
    Vector4 perpendicular();
    void translate(float x, float y);
    void rotate(float angle);
    void scale(float a, float b);
    void print();
    Vector4 cross(Vector4 temp);
};

float determinant(Vector2 a, Vector2 b);

#endif