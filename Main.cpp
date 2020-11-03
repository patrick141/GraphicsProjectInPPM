#include <iostream>
#include <cmath>
#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Matrix.h"
#include "Model.h"
using namespace std;

/*
    CSC 350 Project CheckPoint #2
    by Patrick Amaro Rivera, Robin Bista and Rana Hamza.
*/

int main()
{
	Model teapot = Model();
	teapot.readfromObj("./teapot.obj", Red);
	Triangle3D t(Vector4(0,0,0,1), Vector4(40,0,0,1), Vector4(40,40,0,1), Red, Blue, Green);
	cout <<  teapot.numTriangles() << endl;
	teapot[0].v1.print();
	Color c1(0.43, 0.23,1.00,0.94);
	Color c2 = c1 * 1.2;
	Color c3 = c1 + c2;
	Color c4(0.32,0.39,0.21,0.32);

	Raster p(300, 300, Black);
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

	Triangle2D t3(Vector2(p.getWidth() / 2 -30, p.getHeight() /2 ), Vector2(p.getWidth() /2 + 30,p.getHeight()/2),
	Vector2(p.getWidth()/2,p.getHeight() /2 + 37),Green, Purple, Green);
	p.drawTriangle2D_DotProduct(t3);

	Matrix4 A(1 , 2 , 3 , 4 ,5 , 6 , 7 , 8 ,9 , 10 , 11 , 12 ,13 , 14 , 15 , 16);
	Matrix4 B(17 , 18 , 19 , 20 ,21 , 22 , 23 , 24 ,25 , 26 , 27 , 28 ,29 , 30 , 31 , 32);
	Matrix4 C = A *B;
	Vector4 v11(1,2,3,4);

	p.writeToPPM();
	return 0;
}
