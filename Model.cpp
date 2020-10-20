#include "Model.h"
#include <fstream>

Model::Model()
{
    triangles = NULL;
}

void Model::readfromObj()
{
    return;
}

int Model::numTriangles()
{
    return triangles.size();
}