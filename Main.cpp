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
    CSC 350 Project CheckPoint #3
    by Patrick Amaro Rivera, Robin Bista and Rana Hamza.
*/

int main()
{
	Raster p(100, 100, White);
	Model teapot = Model();
	teapot.readfromObj("./teapot.obj", Orange);
	Matrix4 modelMatrixTeapot = Translate3D(50,50,-40)* RotateZ3D(45.0) * Scale3D(0.5,0.5,0.5);
	Matrix4 viewMatrix = LookAt(Vector4(50,50,30,1),Vector4(50,50,-40,1),Vector4(0,1,0,0));
	Matrix4 perspectiveMatrix = Perspective(90.0, p.getWidth() / p.getHeight(), 0.01, 1000.0);
	Matrix4 viewportMatrix = Viewport(0,0,p.getWidth(), p.getHeight());
	modelMatrixTeapot.print();
	cout << "------------" << endl;
	viewMatrix.print();
	cout << "------------" << endl;
	teapot.transform(modelMatrixTeapot);
	Vector4 a1(1,1,1,1);
	Vector4 a2(4,3,3,1);
	Vector4 c = a1.cross(a2);
	c.print();
	p.drawModel(teapot);
	p.writeToPPM();
	return 0;
}