#ifndef Raster_H
#define Raster_H
#include "Color.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class Raster
{
    private:
        int width;
        int height;
        Color* pixels;
        
    public:
        Raster();
        Raster(int pWidth, int pHeight, Color pFillColor);

        ~Raster();
        int getWidth();
        int getHeight();

        Color getColorPixel(int x, int y);
        void setColorPixel(int x, int y, Color pFillColor);
        void clear(Color pFillColor);
        void writeToPPM();
        void drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
        float findSlope(float xR, float xL, float yR, float yL);

        void drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2);
        void drawCurve(Vector2 v1, Vector2 v2, Vector2 center, float radius, Color c1);
        void drawTriangle2D_DotProduct(Triangle2D triangle);
        void drawTriangle_Barycentric(Triangle2D T);
        void drawTriangle3D_Barycentric(Triangle3D triangle);
        void drawRectangle(Rectangle2D R);
        void drawCirclePoints(Circle2D c);
        void drawCircle(Circle2D circle);
};

#endif