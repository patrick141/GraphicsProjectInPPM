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
    v1.x = a1.x;
    v1.y = a1.y;
    v2.x = a2.x;
    v2.y = a2.y;
    v3.x = a3.x;
    v3.y = a3.y;

    c1 = b1;
    c2 = b2;
    c3 = b3;
}

bool Triangle2D::inside(int x, int y)
{
    int result1, result2, result3;
    Vector2 P(x,y);

    Vector2 edgeP1 = (v2 -v1).perpendicular();
    Vector2 g1 = P - v1;
    result1 = edgeP1.dot(g1);

    Vector2 edgeP2 = (v3 -v2).perpendicular();
    Vector2  g2 = P - v2;
    result2 = edgeP2.dot(g2);

    Vector2  edgeP3 = (v1 -v3).perpendicular();
    Vector2  g3 = P - v3;
    result3 = edgeP3.dot(g3);

    if(result1 >= 0 && result2 >= 0 && result3 >= 0){
        return true;
    } else{
        return false;
    }
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3)
{
    return;
}