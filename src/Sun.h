#ifndef SUN_H_
#define SUN_H_

#include "AbstractCelestialBody.h"

class Sun : public AbstractCelestialBody
{
public:

   Sun();

   ~Sun();

   void doRender();

};

#endif /* SUN_H_ */
