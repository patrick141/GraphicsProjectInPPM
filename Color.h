#ifndef Color_H
#define Color_H
#define Red Color(1.0,0.0,0.0,1.0)
#define Green Color(0.0,1.0,0.0,1.0)
#define Blue Color(0.0,0.0,1.0,1.0)
#define White Color(1.0,1.0,1.0,1.0)
#define Black Color(0.0,0.0,0.0,1.0)
#define Yellow Color(1.0,1.0,0.0,1.0)
#define Orange Color(1.0,0.5,0.0,1.0)
#define Purple Color(1.0,0.5,1.0,1.0)
#define Gray Color(0.5,0.5,0.5,1.0)

#include <iostream>

struct Color
{
    float red;
    float green;
    float blue;
    float alpha;

    Color();
    Color(float pRed, float pGreen, float pBlue, float pAlpha);
    void clamp();

    Color operator+(const Color& b);
    Color operator-(const Color& b);
    Color operator*(float b);
    bool operator==(const Color& b);
    void myRGBA();
};


#endif