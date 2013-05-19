#include "BigBang.h"
#include "SolarSystem.h"
#include "TestPlanet.h"

BigBang::BigBang()
{
}

ISolarSystemSP BigBang::bang()
{
   SolarSystem* pSolarSystem = new SolarSystem();

   pSolarSystem->addCelestialBody(ICelestialBodySP(new TestPlanet()));

   return ISolarSystemSP(pSolarSystem);
}
