#ifndef TESTPLANET_H_
#define TESTPLANET_H_

#include "ICelestialBody.h"
#include "GL/glu.h"

class Spheroid;

class TestPlanet : public ICelestialBody
{
public:

   TestPlanet();

   ~TestPlanet();

   void draw();

private:

   Spheroid* m_sphere;

};

#endif /* TESTPLANET_H_ */
