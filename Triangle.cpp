#include "Triangle.h"

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

Triangle2D::Triangle2D(Triangle3D triangle)
{
    v1 = Vector2(triangle.v1.x, triangle.v1.y);
	v2 = Vector2(triangle.v2.x, triangle.v2.y);
	v3 = Vector2(triangle.v3.x, triangle.v3.y);
    c1 = triangle.c1;
    c2 = triangle.c2;
    c3 = triangle.c3;
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

void Triangle2D::translate(float x, float y)
{
    v1.translate(x,y);
    v2.translate(x,y);
    v3.translate(x,y);
}

void Triangle2D::rotate(float angle)
{
    v1.rotate(angle);
    v2.rotate(angle);
    v3.rotate(angle);
}

void Triangle2D::scale(float x, float y)
{
    v1.scale(x,y);
    v2.scale(x,y);
    v3.scale(x,y);
}

Triangle3D::Triangle3D()
{

    v1 = Vector4(0.0 ,0.0, 0.0, 1.0);
    v2 = Vector4(0.0 ,0.0, 0.0, 1.0);
    v3 = Vector4(0.0 ,0.0, 0.0, 1.0);

    c1 = White;
    c2 = White;
    c3 = White;
}

Triangle3D::Triangle3D(Vector4 pV1, Vector4 pV2,Vector4 pV3,Color pC1, Color pC2, Color pC3)
{
    v1 = pV1;
    v2 = pV2;
    v3 = pV3;

    c1 = pC1;
    c2 = pC2;
    c3 = pC3;
}

void Triangle3D::transform(Matrix4 matrix)
{
    v1 = matrix * v1;
    v2 = matrix * v2;
    v3 = matrix * v3;
}
