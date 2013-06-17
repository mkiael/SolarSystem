#pragma once

#include <memory>
#include "Vector3.h"
#include "State.h"

//! @brief Interface for celestial bodies.
class ICelestialBody
{
public:

   virtual ~ICelestialBody() {}

   virtual void simulate(const Vector3& f, double t, double dt) = 0;

   //! Draws the celestial body.
   virtual void render(double alpha) = 0;

   virtual const State& getState() const = 0;

   virtual double getMass() const = 0;

};

typedef std::shared_ptr<ICelestialBody> ICelestialBodySP;
