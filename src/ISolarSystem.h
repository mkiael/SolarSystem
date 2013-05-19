#ifndef ISOLARSYSTEM_H_
#define ISOLARSYSTEM_H_

#include <memory>

//! @brief Interface for our solar system.
class ISolarSystem
{
public:

   virtual ~ISolarSystem() {}

   //! Draws the solar system.
   virtual void draw() = 0;

};

typedef std::shared_ptr<ISolarSystem> ISolarSystemSP;

#endif /* ISOLARSYSTEM_H_ */
