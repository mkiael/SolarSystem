#include "Triangle.h"
#include <GL/gl.h>
#include <GL/glu.h>

Triangle::Triangle(Vertex *v1, Vertex *v2, Vertex *v3)
: m_v1(*v1)
, m_v2(*v2)
, m_v3(*v3)
{

}

void Triangle::draw() const
{
   // For each corner of a triangle
      glVertex3d( m_v1.getPos().getX(), m_v1.getPos().getY(), m_v1.getPos().getZ());
      glVertex3d( m_v2.getPos().getX(), m_v2.getPos().getY(), m_v2.getPos().getZ());
      glVertex3d( m_v3.getPos().getX(), m_v3.getPos().getY(), m_v3.getPos().getZ());
}
