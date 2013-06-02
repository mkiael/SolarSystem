#include "Triangle.h"
#include <GL/gl.h>
#include <GL/glu.h>

Triangle::Triangle(Vertex *v1, Vertex *v2, Vertex *v3)
: m_v1(*v1)
, m_v2(*v2)
, m_v3(*v3)
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

