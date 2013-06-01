#include "SolarSystem.h"
#include "Vector3.h"

// TBR
#include <iostream>

static const double G = 6.674e-11;

SolarSystem::SolarSystem()
: m_celestialBodies()
{
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::draw(double delta)
{
   auto spSun = m_celestialBodies[0];
   for (unsigned int i = 1; i < m_celestialBodies.size(); ++i)
   {
      auto spBody = m_celestialBodies[i];

      // Get distance between bodies
      double r = distance(spSun->getPosition(), spBody->getPosition());

      // Calculate the force
      double f = G * (spSun->getMass() * spBody->getMass()) / (r*r);

      // Calculate the acceleration for the body
      double acc = f / spBody->getMass();

      // Create an acceleration vector
      Vector3 accVec = spSun->getPosition() - spBody->getPosition();;
      accVec = accVec * (acc * delta);

      // Update velocity
      Vector3 velocity = spBody->getVelocity() + accVec;
      spBody->setVelocity(velocity);
   }

   for (auto spCelestialBody : m_celestialBodies)
   {
      spCelestialBody->draw(delta);
   }
}

void SolarSystem::addCelestialBody(const ICelestialBodySP& spCelestialBody)
{
   m_celestialBodies.push_back(spCelestialBody);
}
