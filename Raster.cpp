#include "Raster.h"
#include "Color.h"
#include <new>
#include <cmath>
#include <iostream>
#include <fstream>

Raster::Raster()
{
    width = 0;
    height = 0;
    pixels = NULL;
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
}

Raster::~Raster()
{
    delete[] pixels;
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
	Color fillColor = Red;
    if (x1 == x2)
    {
		int ymin = fminf(y1,y2);
		int ymax = fmax(y1,y2);
        for (int y = ymax; y >= ymin; y--)
        {
			Vector2 v1(x1,ymax);
    		Vector2 v2(x1,y);
			Vector2 temp = v2 - v1;
			float ratio= ymax - y;
			//float ratio = temp.magnitude();
            Color fillColor = (color2 * ratio)+ (color1 * (1- ratio));
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

void Raster::drawTriangle2D_DotProduct(Triangle2D triangle)
{
	Vector2 v1 = triangle.v1;
	Vector2 v2 = triangle.v2;
	Vector2 v3 = triangle.v3;

	int xmin = fminf(v1.x, fminf(v2.x, v3.x));
	int xmax = fmaxf(v1.x, fmaxf(v2.x, v3.x));
	int ymin = fminf(v1.y, fminf(v2.y, v3.y));
	int ymax = fmaxf(v1.y, fmaxf(v2.y, v3.y));

	for(int x = xmin; x <= xmax; x++){
		for(int y = ymin; y <= ymax; y++){
			if(triangle.inside(x,y)){
			setColorPixel(x,y,triangle.c1);
			}
		}
	}
}