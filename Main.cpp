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
    Color c1(1.0f, .25f, .25f, .25f);
	Color c2(0.0f, .5f, 1.0f, .60f);
	Color c3 = c1 + c2;
	std::cout << "Addition" << std::endl;
	c3.myRGBA();
	Color c4(1.0f, .25f, .25f, .40f);
	Color c5(0.25f, .5f, 0.10f, .10f);
	Color c6 = c4 - c5;
	std::cout << "Subtraction" << std::endl;
	c6.myRGBA();
	Color c7(.25f, .38f, .75f, .50f);
	Color c8 = c7 * 2.0f;
	std::cout << "Multiplication" << std::endl;
	c8.myRGBA();
	Color red = Red;
	Color green = Green;
	Color blue = Blue;
	Color black = Black;
	Color white = White;

	std::cout << "Red" << std::endl;
	red.myRGBA();
	std::cout << "Green" << std::endl;
	green.myRGBA();
	std::cout << "Blue" << std::endl;
	blue.myRGBA();
	std::cout << "Black" << std::endl;
	black.myRGBA();
	std::cout << "White" << std::endl;
	white.myRGBA();
	Raster p(20,20, Red);

    p.setColorPixel(23,2,c1);
	p.drawLine_DDA(5,7,7,5,c8);
    p.drawLine_DDA(13,14,15,17, c4);
    p.setColorPixel(12,4, c3);
    p.setColorPixel(19,19,Black);
    p.drawLine_DDA(1,3,3,3,Green);
    p.drawLine_DDA(1,3,1,6,Green);
    p.drawLine_DDA(3,3,3,6,Green);
    p.drawLine_DDA(1,6,3,6,Green);
    Color cc(0.2,0.4,0.6,1.0);
	Color myC = cc * 1.2;
    p.drawLine_DDA(0,0,19,12,myC);
    myC.myRGBA();
	p.writeToPPM();
	Vector2 a(1.2,3.4);
	Vector2 b(1.5,6.3);
	cout << determinant(a,b) << endl;
	Vector2 w = b.perpendicular();
	cout << w.x << " " << w.y << endl;
	cout << w.dot(a) << endl;
	return 0;
}
