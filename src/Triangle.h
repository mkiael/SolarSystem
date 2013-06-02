#pragma once


#include "Vertex.h"
#include "IPrimitive.h"

class Triangle : IPrimitive
{
public:
   Triangle(Vertex *v1, Vertex *v2, Vertex *v3);
   void draw() const;

private:
   void setNormals();
   Vertex m_v1;
   Vertex m_v2;
   Vertex m_v3;
};
