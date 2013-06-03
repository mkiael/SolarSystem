#pragma once

#include "Vertex.h"
#include "IPrimitive.h"

class Triangle : IPrimitive
{
public:
   Triangle(Vertex v1, Vertex v2, Vertex v3);

   void draw() const;

   Vertex getV1() const
   {
      return m_v1;
   }

   Vertex getV2() const
   {
      return m_v2;
   }

   Vertex getV3() const
   {
      return m_v3;
   }

private:
   void setNormals();

   Vertex m_v1;
   Vertex m_v2;
   Vertex m_v3;
};
