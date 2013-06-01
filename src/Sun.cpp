#include "Sun.h"

Sun::Sun()
: AbstractCelestialBody()
{
   m_mass = 10000000000.0;
}

Sun::~Sun()
{
}

void Sun::draw(double delta)
{
   glTranslatef(m_position.getX(), m_position.getY(), m_position.getZ());
   m_sphere.draw(0.0, 0.0, 0.0);
}
