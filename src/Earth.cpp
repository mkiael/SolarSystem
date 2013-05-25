#include "Earth.h"

Earth::Earth()
: m_sphere(2, 5, 10)
, m_rotAngle(0.0)
{
}

Earth::~Earth()
{
}

void Earth::draw(double delta)
{
   m_rotAngle += 360.0 * (delta / 10.0);
   glRotatef(m_rotAngle, 0.0f, 1.0f, 0.0f);
   glTranslatef(8.0f, 0.0f, 0.0f);
   m_sphere.draw(0.0f,0.0f,0.0f);
}
