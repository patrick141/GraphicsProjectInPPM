#ifndef Circle2D_H
#define Circle2D_H
#include <cmath>
#include "Color.h"
#include "Vector2.h"

struct Circle2D {
    Vector2 center;
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
    Vector2 v4;
    float radius;
    Color c1;

    Circle2D();
    Circle2D(float xc, float yc, float radius, Color a1);
    void translate(float x, float y);
    void printVectors();
};

#endif