#include "Raster.h"
#include <new>
#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>

Raster::Raster()
{
    width = 0;
    height = 0;
    pixels = NULL;
	depthPixels = NULL;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor)
{
    width = pWidth;
    height = pHeight;
    int size = width * height;
    pixels = new Color[size];
    for(int i = 0; i < size; i ++){
        pixels[i] = pFillColor;
    }
	depthPixels = new float[size];
	for(int i = 0; i < size; i ++){
        depthPixels[i] = numeric_limits<float>::max();
    }
}

Raster::~Raster()
{
    delete[] pixels;
	delete[] depthPixels;
}

int Raster::getWidth()
{
    return width;
}

int Raster::getHeight()
{
    return height;
}

Color Raster::getColorPixel(int x, int y)
{
    if(x < 0 || x > width - 1|| y < 0 || y > height - 1){
        return White; 
    }
    int temp = height - y - 1;
    int myPixel = temp * width + x;
    return pixels[myPixel];
}

void Raster::setColorPixel(int x, int y, Color pFillColor)
{
    if(x < 0 || x > width - 1|| y < 0 || y > height - 1){
        return;
    }
    int temp = height - y - 1;
    int myPixel = temp * width + x;
    pixels[myPixel] = pFillColor;
}

void Raster::clear(Color pFillColor)
{
    for(int i = 0;i < width * height; i ++)
    {
        pixels[i] = pFillColor;
    }
}

void Raster::writeToPPM()
{
    std:: ofstream output;
    output.open("FRAME_BUFFER.ppm");
    if(!output){
        std::cerr << "Error: The file could not be opened." << std::endl;
    exit(1);
    }
    output << "P3" << std::endl;  
    output << getWidth() << " " << getHeight() << std::endl;
    output  << "255" << std::endl;
    output << std::endl;
    
    int count = 0;
    for (int row = height - 1; row >= 0; row--){
        for (int column = 0; column < width; column ++){
            Color current = getColorPixel(column,row);
            if(column == width -1){
                output << round(current.red * 255) << " " << round(current.green * 255) << " " << round(current.blue * 255) << std::endl;
            }
            else{
                output << round(current.red * 255) << " " << round(current.green * 255) << " " << round(current.blue * 255) << " ";
            }
            count++;
        }
    }
    output.close();
}

void Raster::drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor)
{
    if (x1 == x2)
    {
        for (int y = fmaxf(y1, y2); y >= fminf(y1, y2); y--)
        {
            setColorPixel(x1, y, fillColor);
        }
    }
	else if (findSlope(x1, x2, y1, y2) > 1.0)
    {
		if (y1 > y2)
        {
        	float theSlope = findSlope(y2, y1, x2, x1);
			float x = x1;
			for (int i = y1; i >= y2; i--)
            {
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
		else if (y2 > y1)
        {
			float theSlope = findSlope(y1, y2, x1, x2);
			float x = x2;
			for (int i = y2; i >= y1; i--)
            {
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
		
	}
	else if (findSlope(x1, x2, y1, y2) < -1.0){
		if (y1 > y2){
			float theSlope = findSlope(y2, y1, x2, x1);
			float x = x1;
			for (int i = y1; i >= y2; i--){
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
		else if (y2 > y1){
			float theSlope = findSlope(y1, y2, x1, x2);
			float x = x2;
			for (int i = y2; i >= y1; i--){
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
	}
	else if (y1 == y2){
		for (int x = fminf(x1, x2); x <= fmaxf(x1, x2); x++){
			setColorPixel(x, y1, fillColor);
		}
	}
	else if (x1 < x2){
		float theSlope = findSlope(x1, x2, y1, y2);
		float y = y1;
		for (int i = x1; i <= x2; i++){
			setColorPixel(i, round(y), fillColor);
			y += theSlope;
		}
	}
	else if (x2 < x1){
		float theSlope = findSlope(x2, x1, y2, y1);
		float y = y2;
		for (int i = x2; i <= x1; i++){
			setColorPixel(i, round(y), fillColor);
			y += theSlope;
		}
	}
}

float Raster::findSlope(float xL, float xR, float yL, float yR)
{
    float slope = (yL - yR) / (xL - xR);
    return slope; 
}

void Raster::drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2)
{
	Vector2 v1(x1, y1);
	Vector2 v2(x2, y2);
	float distance = (v2 - v1).magnitude();

    if (x1 == x2)
    {
		for (int y = fmaxf(y1, y2); y >= fminf(y1, y2); y--)
		{
			Vector2 point(x1, y);
			float pointLength = (point - v1).magnitude();
			float ratio = pointLength / distance;
			Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
			setColorPixel(x1, y, fillColor);
		}
    }
	
	else if (findSlope(x1, x2, y1, y2) > 1.0)
    {
		if (y1 > y2)
        {
        	float theSlope = findSlope(y2, y1, x2, x1);
			float x = x1;
			for (int i = y1; i >= y2; i--)
            {
				Vector2 point(round(x),i);
				float pointLength = (point - v1).magnitude();
				float ratio = pointLength / distance;
				Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
				setColorPixel(round(x),i,fillColor);
				x -= theSlope;
			}
		}
		
		else if (y2 > y1)
        {
			float theSlope = findSlope(y1, y2, x1, x2);
			float x = x2;
			for (int i = y2; i >= y1; i--)
            {
				Vector2 point(round(x) ,i);
				float pointlength = (point -v1).magnitude();
				float ratio = pointlength / distance; 
				Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
		
	}
	else if (findSlope(x1, x2, y1, y2) < -1.0){
		if (y1 > y2){
			float theSlope = findSlope(y2, y1, x2, x1);
			float x = x1;
			for (int i = y1; i >= y2; i--){
				Vector2 point(round(x), i);
				float pointLength = (point - v1).magnitude();
				float ratio = pointLength / distance;
				Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
	
		else if (y2 > y1){
			float theSlope = findSlope(y1, y2, x1, x2);
			float x = x2;
			for (int i = y2; i >= y1; i--)
			{
				Vector2 point(round(x), i);
				float pointLength = (point - v1).magnitude();
				float ratio = pointLength / distance;
				Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
				setColorPixel(round(x), i, fillColor);
				x -= theSlope;
			}
		}
	}
	
	else if (y1 == y2){
        for (int x = fminf(x1,x2); x <= fmaxf(x1,x2); x++)
        {
			Vector2 point(x, y1);
			float pointLength = (point - v1).magnitude();
			float ratio = pointLength / distance;
			Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
			setColorPixel(x, y1, fillColor);
        }
	}
	
	else if (x1 < x2){
		float theSlope = findSlope(x1, x2, y1, y2);
		float y = y1;
		for (int i = x1; i <= x2; i++){
			Vector2 point(i, round(y));
			float pointDistance = (point - v1).magnitude();
			float ratio = pointDistance / distance;
			Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
			setColorPixel(i, round(y), fillColor);
			y += theSlope;
		}
	}
	else if (x2 < x1){
		float theSlope = findSlope(x2, x1, y2, y1);
		float y = y2;
		for (int i = x2; i <= x1; i++){
			Vector2 point(i, round(y));
			float pointDistance = (point - v1).magnitude();
			float ratio = pointDistance / distance;
			Color fillColor = (color2 * ratio) + (color1 * (1.0 - ratio));
			setColorPixel(i, round(y), fillColor);
			y += theSlope;
		}
	} 
}

void Raster::drawTriangle2D_DotProduct(Triangle2D triangle)
{
	int xmin = round(fminf(triangle.v1.x, fminf(triangle.v2.x, triangle.v3.x)));
	int xmax = round(fmaxf(triangle.v1.x, fmaxf(triangle.v2.x, triangle.v3.x)));
	int ymin = round(fminf(triangle.v1.y, fminf(triangle.v2.y, triangle.v3.y)));
	int ymax = round(fmaxf(triangle.v1.y, fmaxf(triangle.v2.y, triangle.v3.y)));

	xmin = fmax(0, xmin);
	xmax = fmin(width, xmax);
	ymin = fmax(0,ymin);
	ymax = fmin(height, ymax); 
	
	for(int x = xmin; x <= xmax; x++){
		for(int y = ymin; y <= ymax; y++){
			if(triangle.inside(x,y)){
				setColorPixel(x,y,triangle.c1);
			}
		}
	}
}
/*
//TODO: Fix this method so it draws better
void Raster::drawTriangle3D_Barycentric(Triangle3D triangle)
{
	Triangle2D t(triangle);
	
	Vector2 edge1 = t.v2 - t.v1 ;
	Vector2 edgeP1 = edge1.perpendicular();

	Vector2 edge2 = t.v3 -t.v2 ;
	Vector2 edgeP2 = edge2.perpendicular();

	Vector2 edge3 = t.v1 - t.v3 ;
	Vector2 edgeP3 = edge3.perpendicular();


	int rightMostX = fmax(fmax(triangle.v2.x, triangle.v3.x), triangle.v1.x);
	int leftMostX = fmin(fmin(triangle.v2.x, triangle.v3.x), triangle.v1.x);
	int topMostY = fmax(fmax(triangle.v2.y, triangle.v3.y), triangle.v1.y);
	int bottomMostY = fmin(fmin(triangle.v2.y, triangle.v3.y), triangle.v1.y);

	if(rightMostX >= width){
		rightMostX = width -1;
	}
	if (leftMostX < 0) {
		leftMostX= 0;
	}
	if(topMostY >= height){
		topMostY = height -1;

	}
	if(bottomMostY <0){
		bottomMostY = 0;
	}

	for (int row1 = topMostY; row1 >=bottomMostY; row1--){
		for(int column1 = leftMostX; column1<rightMostX; column1++){
			Vector2 P(column1,row1);
			float lambda1 = 0.0;
			float lambda2 = 0.0;
			float lambda3 = 0.0;

			t.calculateBarycentricCoordinates(P, lambda1, lambda2,lambda3);
			Color new1 = triangle.c1*lambda1;
			Color new2 = triangle.c2*lambda2;
			Color new3 = triangle.c3*lambda3;
			Color c = new1 + new2 +new3;

			Vector2 i1 = P - t.v1;
			Vector2 i2 = P - t.v2;
			Vector2 i3 = P - t.v3;

			float result1 = edgeP1.dot(i1);
			float result2  = edgeP2.dot(i2);
			float result3 = edgeP3.dot(i3);


		if(result1 > 0 && result2 > 0 && result3 > 0)
		{
			setColorPixel(column1,row1,c);
		}	
		}
	}
}
*/

//Attempt 2

void Raster::drawTriangle3D_Barycentric(Triangle3D triangle)
{
	if(triangle.shouldDraw == true){
		Triangle2D T(triangle);
		Vector2 v1 = T.v1;
		Vector2 v2 = T.v2;
		Vector2 v3 = T.v3;
		float f1;
		float f2;
		float f3;

		int xmin = fminf(v1.x, fminf(v2.x, v3.x));
		int xmax = fmaxf(v1.x, fmaxf(v2.x, v3.x));
		int ymin = fminf(v1.y, fminf(v2.y, v3.y));
		int ymax = fmaxf(v1.y, fmaxf(v2.y, v3.y));
		xmin = fmax(0, xmin);
		xmax = fmin(width, xmax);
		ymin = fmax(0,ymin);
		ymax = fmin(height, ymax);

		for(int x = xmin; x <= xmax; x++){
			for(int y = ymin; y <= ymax; y++){
				T.calculateBarycentricCoordinates(Vector2(x,y), f1, f2, f3);
				if(f1 >= 0 && f2 >= 0 && f3 >= 0){
					Color fillColor = T.c1 * f1 + T.c2 * f2 + T.c3 * f3;
					float depth;
					setColorPixel(x, y, fillColor);
				}
			}
		}
	}
}

void Raster::drawTriangle_Barycentric(Triangle2D T)
{
	Vector2 v1 = T.v1;
	Vector2 v2 = T.v2;
	Vector2 v3 = T.v3;
	float f1;
	float f2;
	float f3;

	int xmin = fminf(v1.x, fminf(v2.x, v3.x));
	int xmax = fmaxf(v1.x, fmaxf(v2.x, v3.x));
	int ymin = fminf(v1.y, fminf(v2.y, v3.y));
	int ymax = fmaxf(v1.y, fmaxf(v2.y, v3.y));
	xmin = fmax(0, xmin);
	xmax = fmin(width, xmax);
	ymin = fmax(0,ymin);
	ymax = fmin(height, ymax);

	for(int x = xmin; x <= xmax; x++){
		for(int y = ymin; y <= ymax; y++){
			T.calculateBarycentricCoordinates(Vector2(x,y), f1, f2, f3);
			if(f1 >= 0 && f2 >= 0 && f3 >= 0){
				Color fillColor = T.c1 * f1 + T.c2 * f2 + T.c3 * f3;
				setColorPixel(x, y, fillColor);
			}
		}
	}
}


void Raster::drawModel(Model model)
{
	for(int i = 0; i < model.numTriangles(); i ++){
		Triangle3D t = model[i];
		drawTriangle3D_Barycentric(t);
	}
}
float Raster::getDepthPixel(int x, int y)
{
	if(x < 0 || x > width - 1|| y < 0 || y > height - 1){
        return 0; 
    }
    int temp = height - y - 1;
    int myPixel = temp * width + x;
    return depthPixels[myPixel];
}

void Raster::setDepthPixel(int x, int y, float depth)
{
	if(x < 0 || x > width - 1|| y < 0 || y > height - 1){
        return;
    }
    int temp = height - y - 1;
    int myPixel = temp * width + x;
    depthPixels[myPixel] = depth;
}

void Raster::clear(float depth)
{
	for(int i = 0;i < width * height; i ++)
    {
        depthPixels[i] = depth;
    }
}



// Other functions for different shapes
void Raster::drawRectangle(Rectangle2D R)
{
	int xmin = round(fminf(R.v1.x, fminf(R.v2.x, fminf(R.v3.x, R.v4.x))));
	int xmax = round(fmaxf(R.v1.x, fmaxf(R.v2.x, fmaxf(R.v3.x, R.v4.x))));
	int ymin = round(fminf(R.v1.y, fminf(R.v2.y, fminf(R.v3.y, R.v4.y))));
	int ymax = round(fmaxf(R.v1.y, fmaxf(R.v2.y, fmaxf(R.v3.y, R.v4.y))));

	xmin = fmax(0, xmin);
	xmax = fmin(width, xmax);
	ymin = fmax(0,ymin);
	ymax = fmin(height, ymax);

	for(int x = xmin; x <= xmax; x++){
		for(int y = ymin; y <= ymax; y++){
			setColorPixel(x,y,R.c1);
		}
	}

	return;
}

void Raster::drawCirclePoints(Circle2D c)
{
	setColorPixel(c.center.x, c.center.y, c.c1);
	setColorPixel(c.v1.x,c.v1.y, c.c1);
	setColorPixel(c.v2.x,c.v2.y, c.c1);
	setColorPixel(c.v3.x,c.v3.y, c.c1);
	setColorPixel(c.v4.x,c.v4.y, c.c1);
}
void Raster::drawCircle(Circle2D circle)
{
	Vector2 v1 = circle.v1;
	Vector2 v2 = circle.v2;	
	Vector2 v3 = circle.v3;
	Vector2 v4 = circle.v4;
	Vector2 center = circle.center;
	float radius = circle.radius;
	Color c1 = circle.c1;
	drawCurve(v1,v4,center, radius, c1);
	drawCurve(v4,v3,center, radius, c1);
	drawCurve(v3,v2,center,radius,c1);
	drawCurve(v2,v1,center,radius,c1);

	int x1 = circle.v1.x;
	int y1 = circle.v1.y;
	int x2 = circle.v2.x;
	int y2 = circle.v2.y;
}

void Raster::drawCurve(Vector2 v1, Vector2 v2, Vector2 center, float radius, Color c1)
{
	float x1 = v1.x;
	float x2 = v2.x;
	float y1 = v1.y;
	float y2 = v2.y;

	if(x1 < x2){
		for(int x = x1; x <= x2; x++){
			float f1 = 0 - pow(x - center.x, 2.0);
			float f2 = f1 + pow(radius,2.0);
			float y = center.y + sqrt(f2);
			setColorPixel(x,round(y),c1);
			drawLine_DDA(x,round(y),center.x,round(y),c1);
			drawLine_DDA(x,center.y,x,round(y),c1);
		}
		return;
	} else{
		for(int x = x2; x <= x1; x++){
			float f1 = 0 - pow(x - center.x, 2.0);
			float f2 = f1 + pow(radius,2.0);
			float y = center.y - sqrt(f2);
			setColorPixel(x,round(y),c1);
			drawLine_DDA(x,round(y),center.x,round(y),c1);
			drawLine_DDA(x,center.y,x,round(y),c1);
		}
		return;
	}
}