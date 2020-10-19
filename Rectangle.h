#ifndef Rectangle2D_H
#define Rectangle2D_H
#include <cmath>
#include "Color.h"
#include "Vector.h"

struct Rectangle2D{
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
    Vector2 v4;

    Color c1;

    Rectangle2D();
    Rectangle2D(float x1,float y1, float x2, float y2, Color color);
    Rectangle2D(Vector2 a1, Vector2 a2,Vector2 a3,Vector2 a4, Color b1);
    Rectangle2D operator*(float a);
};

#endif

