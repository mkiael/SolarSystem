#include "AbstractCelestialBody.h"

AbstractCelestialBody::AbstractCelestialBody()
: m_sphere(2.0, 10, 20)
, m_position(0.0, 0.0, 0.0)
, m_velocity(0.0, 0.0, 0.0)
, m_mass(0.0)
{
}

AbstractCelestialBody::~AbstractCelestialBody()
{
}
