#include "Earth.h"

Earth::Earth()
: AbstractCelestialBody()
{
   m_position.setX(10.0);
   m_position.setY(0.0);
   m_velocity.setY(1.0);
   m_mass = 1.0;

   setRadius(1);
   m_sphere.setAmbient(Vector3(0.1, 0.7, 0.7));
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
