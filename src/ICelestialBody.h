#ifndef ICELESTIALBODY_H_
#define ICELESTIALBODY_H_

#include <memory>

//! @brief Interface for celestial bodies.
class ICelestialBody
{
public:

   virtual ~ICelestialBody() {}

   //! Draws the celestial body.
   virtual void draw() = 0;

};

typedef std::shared_ptr<ICelestialBody> ICelestialBodySP;

#endif /* ICELESTIALBODY_H_ */
