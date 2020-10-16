#include <iostream>
#include <cmath>
#include "Color.h"
#include "Raster.h"
#include "Vector2.h"
#include "Triangle2D.h"
#include "Rectangle2D.h"
#include "Circle2D.h"
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

	Raster p(250, 250, Black);
	Triangle2D t1(Vector2(2,15), Vector2(72,10), Vector2(45,80), Red, Green, Blue);
	p.drawLine_DDA_Interpolated(1,20,1,90, Purple, Purple);
	p.drawLine_DDA_Interpolated(1,90,26,90, Purple, Blue);
	p.drawLine_DDA_Interpolated(1,50,26,50, Purple, Blue);
	p.drawLine_DDA_Interpolated(1,20,1,90, Purple, Blue);
	p.drawLine_DDA_Interpolated(35,20,35,90, Purple, Blue);
	p.drawLine_DDA_Interpolated(63,20,63,90,Purple, Purple);
	p.drawLine_DDA_Interpolated(50,90,70,90,Purple, Blue);
	p.drawLine_DDA_Interpolated(50,20,63,20,Purple, Blue);
	p.drawLine_DDA_Interpolated(85,20,85,90, Purple, Blue);
	p.drawTriangle_Barycentric(t1);
	Triangle2D t2 = t1;
	t2.translate(p.getWidth() /2, p.getHeight() / 2);
	t2.rotate(22.5);
	t2.c2 = Purple;
	t2.c3 = Orange;
	p.drawTriangle_Barycentric(t2);
	p.drawLine_DDA(0,9,97,9,Green);

	Circle2D cir1(p.getWidth() / 4, p.getHeight() * 3 /4,40, White);
	p.drawCircle(cir1);
	cir1.translate(p.getWidth() / 2, 0);
	p.drawCircle(cir1);

	Circle2D cir2(p.getWidth() / 4, p.getHeight() * 3 /4,20, Blue);
	p.drawCircle(cir2);
	cir2.translate(p.getWidth()/ 2, 0);
	p.drawCircle(cir2);

	Circle2D cir3(p.getWidth() / 4, p.getHeight() * 3 /4,10, Black);
	p.drawCircle(cir3);
	cir3.translate(p.getWidth()/ 2, 0);
	p.drawCircle(cir3);

	Rectangle2D r1(p.getWidth()/4, p.getHeight() /4,p.getWidth() * 3 /4,p.getWidth()/3,Black);
	p.drawRectangle(r1);

	Triangle2D t3(Vector2(p.getWidth() / 2 -30, p.getHeight() /2 ), Vector2(p.getWidth() /2 + 30,p.getHeight()/2),
	Vector2(p.getWidth()/2,p.getHeight() /2 + 37),Green, Purple, Green);
	p.drawTriangle2D_DotProduct(t3);
	p.writeToPPM();

	return 0;
}
