#ifndef EARTH_H_
#define EARTH_H_

#include "AbstractCelestialBody.h"

class ISolarSystem;

class Earth : public AbstractCelestialBody
{
public:

   Earth();

   ~Earth();

   void doRender();

};

#endif /* EARTH_H_ */
