#include "Sun.h"

Sun::Sun()
: AbstractCelestialBody()
{
   m_mass = 100000000000.0;
   m_sphere.setAmbient(Vector3(1.0, 0.5, 0.0));
   m_sphere.setEmissive(Vector3(1.0, 1.0, 0.7));
   setRadius(2.0);
}

Sun::~Sun()
{
}

void Sun::doRender()
{
   Vector3 position(m_currentState.getPosition());
   glTranslatef(position.getX(), position.getY(), position.getZ());
   m_sphere.draw(0.0, 0.0, 0.0);
}
