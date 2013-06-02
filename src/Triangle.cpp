#include "Triangle.h"
#include "Vector3.h"
#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3)
: m_v1(v1)
, m_v2(v2)
, m_v3(v3)
{
   setNormals();
}

//Set Correct normal
void Triangle::setNormals()
{
  Vector3 n1 = m_v1.getPos() - m_v2.getPos();
  Vector3 n2 = m_v2.getPos() - m_v3.getPos();

  Vector3 normal = n1 * n2;
  normal.normalize();

  m_v1.setNormal(normal);
  m_v2.setNormal(normal);
  m_v3.setNormal(normal);
}

std::vector<Triangle> Triangle::subDivide(int times)
{
   return subDivide(times, this);
}

//! @brief Recursion hell
std::vector<Triangle> Triangle::subDivide(int times, Triangle *current)
{
   // If recursion bottom is reached
   if (times == 0) {
      splitTriangles.push_back(*current);
      return splitTriangles;
   }

   // Create 3 new vectors between all the others
   Vector3 p1 = (m_v1.getPos() + m_v2.getPos()) / 2.0;
   Vector3 p2 = (m_v2.getPos() + m_v3.getPos()) / 2.0;
   Vector3 p3 = (m_v3.getPos() + m_v1.getPos()) / 2.0 ;

   //normalize them
   p1.normalize();
   p2.normalize();
   p3.normalize();

   //Send the 4 new triangles into Recursion hell
   subDivide(times-1, new Triangle( Vertex(m_v1), Vertex(p1), Vertex(p3)));
   subDivide(times-1, new Triangle( Vertex(m_v2), Vertex(p2), Vertex(p1)));
   subDivide(times-1, new Triangle( Vertex(m_v3), Vertex(p3), Vertex(p2)));
   subDivide(times-1, new Triangle( Vertex(p1)  , Vertex(p2), Vertex(p3)));

   return splitTriangles;
}

void Triangle::draw() const
{
   // For each corner of a triangle
   glNormal3d(m_v1.getNormal().getX(), m_v1.getNormal().getY(), m_v1.getNormal().getZ());
   glVertex3d( m_v1.getPos().getX(), m_v1.getPos().getY(), m_v1.getPos().getZ());

   glNormal3d(m_v2.getNormal().getX(), m_v2.getNormal().getY(), m_v2.getNormal().getZ());
   glVertex3d( m_v2.getPos().getX(), m_v2.getPos().getY(), m_v2.getPos().getZ());

   glNormal3d(m_v3.getNormal().getX(), m_v3.getNormal().getY(), m_v3.getNormal().getZ());
   glVertex3d( m_v3.getPos().getX(), m_v3.getPos().getY(), m_v3.getPos().getZ());

}

