#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Triangle.h"
#include "Matrix.h"
#include "Color.h"

using namespace std;

class Model {
    private:
        vector<Triangle3D> triangles;
    public:
        Model();
        int numTriangles();
        void readfromObj();
};