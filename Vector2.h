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
};