#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_

#include "ISolarSystem.h"
#include "ICelestialBody.h"
#include <vector>

//! @brief Implementation of a solar system.
class SolarSystem : public ISolarSystem
{
public:

   SolarSystem();

   ~SolarSystem();

   void draw(double delta);

   void addCelestialBody(const ICelestialBodySP& spCelestialBody);

private:

   std::vector<ICelestialBodySP> m_celestialBodies;

};

#endif /* SOLARSYSTEM_H_ */
