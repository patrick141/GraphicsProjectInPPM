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
        triangles[i].transform(matrix);
    }
}

void Model::readfromObj(string file, Color fillColor)
{
    vector<Vector4> vectors;
    vector<Triangle3D> faces;

    ifstream myFile(file);
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            istringstream s(line);
            string myWord;
            vector<string> words;
            while(getline(s, myWord, ' ')){
                words.push_back(myWord);
            }

            if(words[0] == "v"){
                float f1 = atof(words[1].c_str());
                float f2 = atof(words[2].c_str());
                float f3 = atof(words[3].c_str());
                Vector4 v(f1, f2, f3, 1.0);
                vectors.push_back(v);
            } else if(words[0] == "f"){
                float f1 = atof(words[1].c_str());
                float f2 = atof(words[2].c_str());
                float f3 = atof(words[3].c_str());
                Vector4 v(f1, f2, f3, 1.0);
                Triangle3D t(v1,v2,v3,fillColor, fillColor, fillColor);
                triangles.push_back(t);
            }

        }
    }
    return;
}