#include "SolarSystem.h"

SolarSystem::SolarSystem()
: m_celestialBodies()
{
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::draw(double delta)
{
   for (auto spCelestialBody : m_celestialBodies)
   {
      spCelestialBody->draw(delta);
   }
}

void SolarSystem::addCelestialBody(const ICelestialBodySP& spCelestialBody)
{
   m_celestialBodies.push_back(spCelestialBody);
}
