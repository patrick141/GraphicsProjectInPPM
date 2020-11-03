#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Triangle.h"
#include "Matrix.h"
#include "Color.h"
#ifndef Model_H
#define Model_H

using namespace std;

class Model {
    private:
        vector<Triangle3D> triangles;
    public:
        Model();
        int numTriangles();
        void readfromObj(string file, Color fillColor);
        Triangle3D operator[](int i);
        void transform(Matrix4 matrix);
};

#endif