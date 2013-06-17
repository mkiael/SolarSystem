#pragma once

#include "ICelestialBody.h"
#include "ISolarSystem.h"
#include "Spheroid.h"
#include "Vector3.h"
#include "State.h"

//! @brief Abstract base class for celestial bodies.
class AbstractCelestialBody : public ICelestialBody
{
public:

   virtual ~AbstractCelestialBody();

   void simulate(const Vector3& f, double t, double dt);

   void render(double alpha);

   const State& getState() const
   {
      return m_currentState;
   }

   double getMass() const
   {
      return m_mass;
   }

   void setRadius(double radius)
   {
      m_sphere.resize(radius);
   }

protected:

   virtual void doRender() = 0;

   AbstractCelestialBody();

   Spheroid m_sphere;

   State m_previousState;

   State m_currentState;

   double m_mass;

};
