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
	Triangle2D myTriangle(Vector2(2,15), Vector2(72,10), Vector2(45,80), Red, Green, Blue);
	//p.drawTriangle_Barycentric(myTriangle);
	p.drawTriangle2D_DotProduct(myTriangle);
	p.drawLine_DDA_Interpolated(89,13,89,72,Blue, Green);
	p.drawLine_DDA_Interpolated(91,72,91,13,Green, Blue);
	p.drawLine_DDA_Interpolated(1,1,80,1,Green, Red);
	p.drawLine_DDA_Interpolated(80,3,1,3,Red, Green);
	p.drawLine_DDA_Interpolated(90,10,90,40, Black, Red);
	p.drawLine_DDA_Interpolated(4,98,89,90,Red,Blue);
	//Triangle2D t2(Vector2(90,20), Vector2(98,19), Vector2(92,21), c4, Red, Red);
	//p.drawTriangle2D_DotProduct(t2);
	p.writeToPPM();
	return 0;
}
