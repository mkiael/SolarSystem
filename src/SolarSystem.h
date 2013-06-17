#pragma once

#include "ISolarSystem.h"
#include "ICelestialBody.h"
#include <vector>

//! @brief Implementation of a solar system.
class SolarSystem : public ISolarSystem
{
public:

   SolarSystem();

   ~SolarSystem();

   void simulate();

   void render();

   void addCelestialBody(const ICelestialBodySP& spCelestialBody);

private:

   void integrate(double t, double dt);

   std::vector<ICelestialBodySP> m_celestialBodies;

   double m_time;

   double m_currentTime;

   double m_newTime;

   double m_frameTime;

   double m_accumulator;

};
