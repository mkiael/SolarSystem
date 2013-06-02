#pragma once

#include <vector>

#include "Vertex.h"
#include "IPrimitive.h"

class Triangle : IPrimitive
{
public:
   Triangle(Vertex v1, Vertex v2, Vertex v3);
   std::vector<Triangle> subDivide(int times);
   void draw() const;

private:
   std::vector<Triangle> subDivide(int times, Triangle *current);
   void setNormals();

   Vertex m_v1;
   Vertex m_v2;
   Vertex m_v3;

   std::vector<Triangle> splitTriangles;
};
