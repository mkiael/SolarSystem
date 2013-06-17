#pragma once

#include "Vertex.h"

//! @brief A triangle class.
class Triangle
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

   // Sets "fake" smoothness on/off
   void setSmooth(bool smooth)
   {
      m_smoothOn = smooth;
   }

private:

   void setFlatNormals();

   void setSmoothNormal();

   Vertex m_v1;

   Vertex m_v2;

   Vertex m_v3;

   bool m_smoothOn;

};
