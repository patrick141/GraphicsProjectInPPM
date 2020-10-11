#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector2.h"
#include "Triangle2D.h"
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
    Color c1(0.43, 0.23,1.00,0.94);
	Color c2 = c1 * 1.2;
	Color c3 = c1 + c2;
	Color c4(0.32,0.39,0.21,0.32);

	Raster p(100, 100, White);
	Triangle2D myTriangle(Vector2(2,15), Vector2(72,10), Vector2(45,80), Red, Red, Red);
	p.drawTriangle2D_DotProduct(myTriangle);
	p.drawLine_DDA_Interpolated(89,13,89,72,Blue, Green);
	p.drawLine_DDA_Interpolated(1,1,80,1,Green, Red);
	//Triangle2D t2(Vector2(90,20), Vector2(98,19), Vector2(92,21), c4, Red, Red);
	//p.drawTriangle2D_DotProduct(t2);
	p.writeToPPM();
	float a;
	float b;
	float c;
	myTriangle.calculateBarycentricCoordinates(Vector2(1,1),a,b,c);
	cout << a << " " << b <<  " " << c << endl;
	cout << a + b + c << endl;

	return 0;
}
