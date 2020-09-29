#ifndef Triangle2D_H
#define Triangle2D_H
#include <cmath>
#include "Color.h"
#include "Vector2.h"

struct Triangle2D{
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;

    Color c1;
    Color c2;
    Color c3;

    Triangle2D();
    Triangle2D(Vector2 a1, Vector2 a2, Vector2 a3, Color b1, Color b2, Color b3);
    void calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3);
};

#endif