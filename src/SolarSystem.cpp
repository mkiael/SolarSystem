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

      Vector3 oldPosition = spBody->getPosition() - spBody->getVelocity() * delta;

      Vector3 R = spSun->getPosition() - spBody->getPosition();

      double r = vectorMag(R);

      Vector3 F = R * ((G * spSun->getMass() * spBody->getMass()) / (r*r*r));

      // Calculate the acceleration for the body
      Vector3 A = F / spBody->getMass();

      // Update velocity
      Vector3 V = spBody->getVelocity() + A;
      spBody->setVelocity(V);
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
