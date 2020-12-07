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

#define WIDTH 100
#define HEIGHT 100

using namespace std;

/*
    CSC 350 Project CheckPoint #4
    by Patrick Amaro Rivera, Robin Bista and Rana Hamza.
*/

int main()
{
	Raster p(WIDTH, HEIGHT, Red + Blue + Green - Orange);
	Model teapot, bunny;
	//teapot.readfromObj("./teapot.obj", Red);
	bunny.readfromObj("./bunny.obj", Blue);

	Matrix4 modelMatrixTeapot = Translate3D(50,50,-60)* RotateZ3D(45.0)*Scale3D(0.5,0.5,0.5);
	Matrix4 modelMatrixBunny = Translate3D(70,30,-60)* RotateZ3D(-20.0)*Scale3D(500,500,500);

	Matrix4 viewMatrix = LookAt(Vector4(50,50,30,1),Vector4(50,50,-40,1),Vector4(0,1,0,0));

	Matrix4 perspectiveMatrix = Perspective(70.0, p.getWidth() / p.getHeight(), 0.01, 1000.0);

	Matrix4 viewportMatrix = Viewport(0,0,p.getWidth(),p.getHeight());

	bunny.transform(perspectiveMatrix * viewMatrix * modelMatrixBunny);
	bunny.homogenize();
	bunny.transform(viewportMatrix);
	cout << "-----" << endl;
	cout << "Test pixel at 12,12" << endl;
	cout << p.getDepthPixel(12,12) << endl;
	p.drawModel(bunny);
	p.writeToPPM();
	return 0;
}