#include "BigBang.h"
#include "SolarSystem.h"
#include "Sun.h"
#include "Earth.h"

BigBang::BigBang()
{
}

ISolarSystemSP BigBang::bang()
{
   SolarSystem* pSolarSystem = new SolarSystem();

   pSolarSystem->addCelestialBody(ICelestialBodySP(new Sun()));

   pSolarSystem->addCelestialBody(ICelestialBodySP(new Earth()));

   return ISolarSystemSP(pSolarSystem);
}
