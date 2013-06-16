#include "Earth.h"

Earth::Earth()
: AbstractCelestialBody()
{
   m_currentState.setPosition(Vector3(8.0, 0.0, 0.0));
   m_currentState.setVelocity(Vector3(0.0, 0.1, 0.0));
   m_mass = 0.000000001;

   setRadius(1);
   m_sphere.setAmbient(Vector3(0.1, 0.7, 0.7));
}

Earth::~Earth()
{
}

void Earth::doRender()
{
   Vector3 position(m_currentState.getPosition());
   glTranslatef(position.getX(), position.getY(), position.getZ());
   m_sphere.draw(0.0, 0.0, 0.0);
}
