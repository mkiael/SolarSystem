#ifndef ABSTRACTCELESTIALBODY_H_
#define ABSTRACTCELESTIALBODY_H_

#include "ICelestialBody.h"
#include "ISolarSystem.h"
#include "Spheroid.h"
#include "Vector3.h"

class AbstractCelestialBody : public ICelestialBody
{
public:

   virtual ~AbstractCelestialBody();

   void setVelocity(const Vector3& velocity)
   {
      m_velocity = velocity;
   }

   const Vector3& getPosition() const
   {
      return m_position;
   }

   const Vector3& getVelocity() const
   {
      return m_velocity;
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

   AbstractCelestialBody();

   Spheroid m_sphere;

   Vector3 m_position;

   Vector3 m_velocity;

   double m_mass;

};

#endif /* ABSTRACTCELESTIALBODY_H_ */
