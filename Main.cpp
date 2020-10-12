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
	Triangle2D t1(Vector2(1,1), Vector2(99,1), Vector2(45,89), White - Red * 0.2, Green, Purple);
	p.drawTriangle_Barycentric(t1);
	p.drawLine_DDA_Interpolated(0.32,0.42,87.23,98.14, Gray, Purple);
	p.writeToPPM();
	return 0;
}
