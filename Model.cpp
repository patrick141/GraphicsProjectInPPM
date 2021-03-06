#include "Model.h"
#include <fstream>
#include <sstream>

Model::Model()
{
    
}

int Model::numTriangles()
{
    return triangles.size();
}

Triangle3D Model::operator[](int i)
{
    return triangles[i];
}

void Model::transform(Matrix4 matrix)
{
    for(int i = 0; i < numTriangles();i++){
        if(triangles[i].shouldDraw == true){
            triangles[i].transform(matrix);
        }
    }
}

void Model::readfromObj(string file, Color fillColor)
{
    vector<Vector4> vectors;
    ifstream myFile(file);
    if (myFile.is_open()) 
    {
        string line;
        while (getline(myFile, line)) 
        {
            istringstream s(line);
            string myWord;
            float x, y, z;
            bool isVertex;
            bool isFace;
            Vector4 v1, v2, v3;
            int index = 0;
            int v1_i, v2_i, v3_i;

            while (getline(s, myWord, ' ')) 
            {
                if (myWord == "v") {
                    isVertex = true;
                    isFace = false;
                } else if (myWord == "f") {
                    isVertex = false;
                    isFace = true;
                } else if (isVertex) {
                    if (index == 1) {
                        x = atof(myWord.c_str());
                    } else if (index == 2) {
                        y = atof(myWord.c_str());
                    } else if (index == 3) {
                        z = atof(myWord.c_str());
                    }
                } else if (isFace) {
                    if (index == 1) {
                        int v1_index = atoi(myWord.c_str()) - 1;
                        v1_i = v1_index + 1;
                        v1 = vectors[v1_index];
                    } else if (index == 2) {
                        int v2_index = atoi(myWord.c_str()) - 1;
                        v2 = vectors[v2_index];
                        v2_i = v2_index + 1;
                    } else if (index == 3) {
                        int v3_index = atoi(myWord.c_str()) - 1;
                        v3 = vectors[v3_index];
                        v3_i = v3_index + 1;
                    }
                }
                index++;
            }

            if (isVertex) {
                Vector4 v = Vector4(x, y, z, 1.0);
                vectors.push_back(v);
            } else if (isFace) {
                triangles.push_back(Triangle3D(v1, v2, v3, fillColor, fillColor, fillColor));
            }
        }
        myFile.close();
    }
}

void Model::homogenize()
{
    for(int i = 0; i < numTriangles();i++){
        float w1 = triangles[i].v1.w;
        triangles[i].v1.x /= w1;
        triangles[i].v1.y /= w1;
        triangles[i].v1.z /= w1;
        triangles[i].v1.w /= w1;
        
        float w2 = triangles[i].v2.w;
        triangles[i].v2.x /= w2;
        triangles[i].v2.y /= w2;
        triangles[i].v2.z /= w2;
        triangles[i].v2.w /= w2;

        float w3 = triangles[i].v3.w;
        triangles[i].v3.x /= w3;
        triangles[i].v3.y /= w3;
        triangles[i].v3.z /= w3;
        triangles[i].v3.w /= w3;
    }
    return;
}

void Model::performBackfaceCulling(Vector4 eye, Vector4 spot)
{
    for(int i = 0; i < numTriangles();i++){
        Vector4 temp =  spot - eye;
        temp.normalize();
    }
}