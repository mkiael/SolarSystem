#ifndef SUN_H_
#define SUN_H_

#include "ICelestialBody.h"
#include "Spheroid.h"

class Sun : public ICelestialBody
{
public:

   Sun();

   ~Sun();

   void draw(double delta);

public:

   Spheroid m_sphere;

};

#endif /* SUN_H_ */
