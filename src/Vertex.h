#pragma once

#include "Vector3.h"

//! @brief Class for representing a vertex
class Vertex
{
public:

   Vertex(double x, double y, double z);

   Vertex(Vector3 pos);

   ~Vertex();

   void setTextureCoord(double x, double y);

   //Set/Get Position
   const Vector3 &getPos() const
   {
      return m_position;
   }

   void setPos(Vector3 pos)
   {
      m_position = pos;
   }

   //Set/Get Normal
   const Vector3 &getNormal() const
   {
      return m_normal;
   }

   void setNormal(Vector3 &normal)
   {
      m_normal = normal;
   }

   //Set/Get Color
   const Vector3 &getColor() const
   {
      return m_color;
   }

   void setColor(Vector3 &color)
   {
      m_color = color;
   }

private:

   double m_textureCoord[2];

   Vector3 m_position;

   Vector3 m_normal;

   Vector3 m_color;

};
