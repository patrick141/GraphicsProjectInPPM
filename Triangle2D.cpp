#include "Triangle2D.h"
#include <cmath>

Triangle2D::Triangle2D()
{
    v1.x = 0.0;
    v1.y = 0.0;
    v2.x = 0.0;
    v2.y = 0.0;
    v3.x = 0.0;
    v3.y = 0.0;

    c1 = Black;
    c2 = Black;
    c3 = Black;
}

Triangle2D::Triangle2D(Vector2 a1, Vector2 a2, Vector2 a3, Color b1, Color b2, Color b3)
{
    v1 = a1;
    v2 = a2;
    v3 = a3;

    c1 = b1;
    c2 = b2;
    c3 = b3;
}