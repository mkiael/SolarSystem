#ifndef ICELESTIALBODY_H_
#define ICELESTIALBODY_H_

#include <memory>
#include "Vector3.h"

//! @brief Interface for celestial bodies.
class ICelestialBody
{
public:

   virtual ~ICelestialBody() {}

   //! Draws the celestial body.
   virtual void draw(double delta) = 0;

   virtual void setVelocity(const Vector3& v) = 0;

   virtual const Vector3& getVelocity() const = 0;

   virtual const Vector3& getPosition() const = 0;

   virtual double getMass() const = 0;

};

typedef std::shared_ptr<ICelestialBody> ICelestialBodySP;

#endif /* ICELESTIALBODY_H_ */
