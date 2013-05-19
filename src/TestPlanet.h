#ifndef TESTPLANET_H_
#define TESTPLANET_H_

#include "ICelestialBody.h"
#include "GL/glu.h"

class TestPlanet : public ICelestialBody
{
public:

   TestPlanet();

   ~TestPlanet();

   void draw();

private:

   GLUquadric* m_quad;

};

#endif /* TESTPLANET_H_ */
