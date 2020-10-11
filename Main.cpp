#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector2.h"
using namespace std;

/*
    CSC 350 Project CheckPoint #1
    by Patrick Amaro Rivera, Robin Bista and Rana Hamza.
*/
float determinant(Vector2 a, Vector2 b){
	return b.x * a.y - a.x * b.y;
};


int main()
{
    Color c1(0.43, 0.43, 0.43,1.00);
	Raster p(100, 100, White);
	Triangle2D myTriangle(Vector2(2,15), Vector2(72,10), Vector2(45,80), Red, Red, Red);
	p.drawTriangle2D_DotProduct(myTriangle);
	p.setColorPixel(9,2,Red);
	p.writeToPPM();
	return 0;
}
