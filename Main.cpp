#include <iostream>
#include <cmath>
#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Matrix.h"
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

	Raster p(100, 100, Black);
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

	Matrix4 A(1 , 2 , 3 , 4 ,5 , 6 , 7 , 8 ,9 , 10 , 11 , 12 ,13 , 14 , 15 , 16);
	Matrix4 B(17 , 18 , 19 , 20 ,21 , 22 , 23 , 24 ,25 , 26 , 27 , 28 ,29 , 30 , 31 , 32);
	Matrix4 C = A *B;
	Vector4 v11(1,2,3,4);
	Vector4 v12 = A * v11;
	Matrix4 temp = Rotate3D(45,45,45);
	C.print();
	temp.print();
	p.clear(White);
	Triangle3D t(Vector4(0,0,0,1), Vector4(40,0,0,1), Vector4(40,40,0,1), Red, Blue, Green);
	p.drawTriangle3D_Barycentric(t);
	Matrix4 m = Translate3D(0,13,0);
	t.transform(m);
	p.drawTriangle3D_Barycentric(t);
	p.writeToPPM();
	return 0;
	/*
	0.5, 0.5, -0.707107, 0
	-0.146447, 0.853553, 0.5, 0
	0.853553, -0.146447, 0.5, 0
	0, 0, 0, 1
	*/
}
