#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector2.h"
#include "Triangle2D.h"
using namespace std;

/*
    CSC 350 Project CheckPoint #2
    by Patrick Amaro Rivera, Robin Bista and Rana Hamza.
*/

int main()
{
    Color c1(0.43, 0.23,1.00,0.94);
	Color c2 = c1 * 1.2;
	Color c3 = c1 + c2;
	Color c4(0.32,0.39,0.21,0.32);

	Raster p(100, 100, White);
	Triangle2D t1(Vector2(2,15), Vector2(72,10), Vector2(45,80), Red, Green, Blue);
	p.drawTriangle_Barycentric(t1);
	p.drawLine_DDA_Interpolated(10,23,10,51,Green, Red);
	p.drawLine_DDA_Interpolated(10,23,51,23,Green, Red);
	p.drawLine_DDA_Interpolated(72.32,0.42,87.23,98.14, Red, Blue);
	p.writeToPPM();
	return 0;
}
