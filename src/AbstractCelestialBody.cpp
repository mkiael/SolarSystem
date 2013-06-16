#include "AbstractCelestialBody.h"

AbstractCelestialBody::AbstractCelestialBody()
: m_sphere(2.0,2)
, m_previousState()
, m_currentState()
, m_mass(0.0)
{
}

AbstractCelestialBody::~AbstractCelestialBody()
{
}

void AbstractCelestialBody::simulate(const Vector3& f, double t, double dt)
{
   m_previousState = m_currentState;

   // Calculate the acceleration for the body
   Vector3 a = f / m_mass;

   // Update velocity
   Vector3 v = m_currentState.getVelocity() + (a * dt);
   m_currentState.setVelocity(v);

   // Update position
   Vector3 p = m_currentState.getPosition() + v;
   m_currentState.setPosition(p);
}

void AbstractCelestialBody::render(double alpha)
{
   m_currentState = (m_currentState * alpha) + (m_previousState * (1.0 - alpha));
   doRender();
}
