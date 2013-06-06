#include "Sun.h"

Sun::Sun()
: AbstractCelestialBody()
{
   m_mass = 10000000000.0;
   m_sphere.setAmbient(Vector3(1.0, 0.5, 0.0));
   m_sphere.setEmissive(Vector3(1.0, 1.0, 0.7));
   setRadius(5);
}

Sun::~Sun()
{
}

void Sun::draw(double delta)
{
   glTranslatef(m_position.getX(), m_position.getY(), m_position.getZ());
   m_sphere.draw(0.0, 0.0, 0.0);
}
