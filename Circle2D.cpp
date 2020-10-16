#include <cmath>
#include <iostream>
#include "Circle2D.h"
#include "Vector2.h"
#include "Color.h"

Circle2D::Circle2D()
{
    center = Vector2(0.0,0.0);
    v1 = Vector2(0.0,0.0);
    v2 = Vector2(0.0,0.0);
    v3 = Vector2(0.0,0.0);
    v4 = Vector2(0.0,0.0);
    radius = 0;
    c1 = Black;
}

Circle2D::Circle2D(float xc, float yc, float pRadius, Color a1)
{
    center = Vector2(xc, yc);
    radius = pRadius;
    float x1 = xc + pRadius;
    float x2 = xc - pRadius;
    float y1 = yc + pRadius;
    float y2 = yc - pRadius;
    float xmin = fminf(x1,x2);
    float xmax = fmax(x1, x2);
    float ymin = fminf(y1,y2);
    float ymax = fmaxf(y1,y2);
    v1 = Vector2(xmin, yc);
    v2 = Vector2(xc, ymin);
    v3 = Vector2(xmax, yc);
    v4 = Vector2(xc, ymax);
    c1 = a1;
}

void Circle2D::printVectors()
{
    std::cout << "Center x is " << center.x << " Y is " << center.y << std::endl;
    std::cout << "V1 x is " << v1.x << " Y is " << v1.y << std::endl;
    std::cout << "V2 x is " << v2.x << " Y is " << v2.y << std::endl;
    std::cout << "V3 x is " << v3.x << " Y is " << v3.y << std::endl;
    std::cout << "V4 x is " << v4.x << " Y is " << v4.y << std::endl;
}

void Circle2D::translate(float x, float y)
{
    center.translate(x,y);
    v1.translate(x,y);
    v2.translate(x,y);
    v3.translate(x,y);
    v4.translate(x,y);
}