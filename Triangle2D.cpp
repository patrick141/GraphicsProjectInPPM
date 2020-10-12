#include "Triangle2D.h"
#include "Vector2.h"
#include <cmath>

Triangle2D::Triangle2D()
{

    v1 = Vector2(0.0 ,0.0);
    v2 = Vector2(0.0 ,0.0);
    v3 = Vector2(0.0 ,0.0);

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

bool Triangle2D::inside(int x, int y)
{
    Vector2 P(x,y);

    Vector2 edgeP1 = (v2 -v1).perpendicular();
    Vector2 g1 = P - v1;
    float result1 = edgeP1.dot(g1);

    Vector2 edgeP2 = (v3 -v2).perpendicular();
    Vector2  g2 = P - v2;
    float result2 = edgeP2.dot(g2);

    Vector2  edgeP3 = (v1 -v3).perpendicular();
    Vector2  g3 = P - v3;
    float result3 = edgeP3.dot(g3);

    return result1 >= 0 && result2 >= 0 && result3 >= 0;
}    

void Triangle2D::calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3)
{
    float area = determinant(v2 - v3, v1 - v3);
    if(area == 0.0){
        lambda1 = 1.0;
        lambda2 = 0.0;
        lambda3 = 0.0;
    } 
    else {
        lambda1 = determinant(v2 - v3, P - v3) / area;
        lambda2 = determinant(P - v3, v1 - v3) / area;
        lambda3 = 1.0 - lambda1 - lambda2;
    }
}