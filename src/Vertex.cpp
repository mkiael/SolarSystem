#include "Vertex.h"

Vertex::Vertex(double x, double y, double z)
: m_position(x, y, z)
, m_normal(0, 0, 0)
, m_color(0.5, 0.5, 0.5)
{
}

Vertex::Vertex(Vector3 pos)
: m_position(pos)
, m_normal(0, 0, 0)
, m_color(0.5, 0.5, 0.5)
{

}

Vertex::~Vertex()
{

}

void Vertex::setTextureCoord(double x, double y)
{
   m_textureCoord[0] = x;
   m_textureCoord[1] = y;
}
