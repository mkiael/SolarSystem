#ifndef ISOLARSYSTEM_H_
#define ISOLARSYSTEM_H_

#include <memory>
#include <vector>
#include "ICelestialBody.h"

//! @brief Interface for our solar system.
class ISolarSystem
{
public:

   virtual ~ISolarSystem() {}

   //! Make the simulation step
   virtual void simulate() = 0;

   //! Draw the solar system.
   virtual void render() = 0;

};

typedef std::shared_ptr<ISolarSystem> ISolarSystemSP;

#endif /* ISOLARSYSTEM_H_ */
