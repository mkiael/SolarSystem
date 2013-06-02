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

   Sun* pSun = new Sun();
   pSolarSystem->addCelestialBody(ICelestialBodySP(pSun));

   Earth* pEarth = new Earth();
   pSolarSystem->addCelestialBody(ICelestialBodySP(pEarth));

   return ISolarSystemSP(pSolarSystem);
}
