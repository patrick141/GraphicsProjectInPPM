#include "Rectangle.h"

Rectangle2D::Rectangle2D()
{
    v1 = Vector2(0.0,0.0);
    v2 = Vector2(0.0,0.0);
    v3 = Vector2(0.0,0.0);
    v4 = Vector2(0.0,0.0);
}

Rectangle2D::Rectangle2D(Vector2 a1, Vector2 a2,Vector2 a3,Vector2 a4, Color b1)
{
    v1 = a1;
    v2 = a2;
    v3 = a3;
    v4 = a4;
    c1 = b1;
}

Rectangle2D::Rectangle2D(float x1,float y1, float x2, float y2, Color color)
{
    float xmin = fminf(x1, x2);
    float xmax = fmax(x1,x2);
    float ymin = fminf(y1, y2);
    float ymax = fmax(y1,y2);
    
    v1 = Vector2(xmin,ymin);
    v2 = Vector2(xmax,ymin);
    v3 = Vector2(xmin,ymax);
    v4 = Vector2(xmax,ymax);
    c1 = color;
}

Rectangle2D Rectangle2D::operator*(float a)
{
    Rectangle2D r;
    r.v1.x = v1.x;
    r.v1.y = v1.y;
    r.v2.x = v2.x * a;
    r.v2.y = v2.y * a;
    r.v3.x = v3.x * a;
    r.v3.y = v3.y * a;
    r.v4.x = v4.x * a;
    r.v4.y = v4.y * a;
    r.c1 = c1;
    return r;
}