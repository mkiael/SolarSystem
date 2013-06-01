#include "Earth.h"

Earth::Earth()
: AbstractCelestialBody()
{
   m_position.setX(8.0);
   m_position.setY(0.0);
   m_velocity.setY(1.0);
   m_mass = 1.0;
}

Earth::~Earth()
{
}

void Earth::draw(double delta)
{
   m_position = m_position + (m_velocity * delta);
   glTranslatef(m_position.getX(), m_position.getY(), m_position.getZ());
   m_sphere.draw(0.0, 0.0, 0.0);
}
