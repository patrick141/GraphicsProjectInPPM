#ifndef Raster_H
#define Raster_H
#include "Color.h"

class Raster
{
    public:
        int width;
        int height;
        Color* pixels;
        
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
};

#endif