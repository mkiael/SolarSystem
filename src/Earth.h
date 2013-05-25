#ifndef EARTH_H_
#define EARTH_H_

#include "ICelestialBody.h"
#include "Spheroid.h"

class Earth : public ICelestialBody
{
public:

   Earth();

   virtual ~Earth();

   void draw(double delta);

private:

   Spheroid m_sphere;

   double m_rotAngle;

};

#endif /* EARTH_H_ */
