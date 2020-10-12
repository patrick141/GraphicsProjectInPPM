#include <iostream>
#include "Color.h"
#include <cmath>
#include <iomanip>

Color::Color()
{
    red = 0.0;
    green = 0.0;
    blue = 0.0;
    alpha = 0.0;
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
    x.red = red + b.red;
    x.green = green + b.green;
    x.blue = blue + b.blue;
    x.alpha = alpha + b.alpha;
    clamp();
    return x;
}

Color Color::operator-(const Color& b)
{
    Color x;
    x.red = red - b.red;
    x.green = green - b.green;
    x.blue = blue - b.blue;
    x.alpha = alpha - b.alpha;
    clamp();
    return x;
}

Color Color::operator*(float b)
{
    Color x;
    x.red = red * b;
    x.green = green * b;
    x.blue = blue * b;
    x.alpha = alpha * b;
    clamp();
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
