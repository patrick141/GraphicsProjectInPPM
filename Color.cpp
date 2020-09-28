#include <iostream>
#include "Color.h"
#include <cmath>
#include <iomanip>

Color::Color()
{
    red = 0;
    green = 0;
    blue = 0;
    alpha = 0;
}

Color::Color(float pRed, float pGreen, float pBlue, float pAlpha)
{
    red = pRed;
    green = pGreen;
    blue = pBlue;
    alpha = pAlpha;
    clamp();
}

void Color::clamp()
{
    red = fmin(fmax(red, 0.0),1.0);
    green = fmin(fmax(green, 0.0), 1.0);
    blue = fmin(fmax(blue, 0.0), 1.0);
    alpha = fmin(fmax(alpha, 0.0), 1.0);
}

Color Color::operator+(const Color& b)
{
    Color x;
    x.red = fmin(fmax(red + b.red, 0.0), 1.0);
    x.green = fmin(fmax(green + b.green, 0.0), 1.0);
    x.blue = fmin(fmax(blue + b.blue, 0.0), 1.0);
    x.alpha = fmin(fmax(alpha + b.alpha, 0.0), 1.0);
    return x;
}

Color Color::operator-(const Color& b)
{
    Color x;
    x.red = fmin(fmax(red - b.red, 0.0), 1.0);
    x.green = fmin(fmax(green - b.green, 0.0), 1.0);
    x.blue = fmin(fmax(blue - b.blue, 0.0), 1.0);
    x.alpha = fmin(fmax(alpha - b.alpha, 0.0), 1.0);
    return x;
}

Color Color::operator*(float b)
{
    Color x;
    x.red = fmin(fmax(red * b, 0.0), 1.0);
    x.green = fmin(fmax(green * b, 0.0), 1.0);
    x.blue = fmin(fmax(blue * b, 0.0), 1.0);
    x.alpha = fmin(fmax(alpha * b, 0.0), 1.0);
    return x;
}

bool Color::operator==(const Color&b)
{
    return (b.red == red) && (b.green == green) && (b.blue == blue) && (b.alpha == alpha);
}

void Color::myRGBA()
{
    std::cout << "Red: " << red << " Green: " << green << " Blue: " << blue << " Alpha: " << alpha << std::endl;
}
