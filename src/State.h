#ifndef STATE_H_
#define STATE_H_

#include "Vector3.h"

class State
{
public:

   State();

   ~State();

   const Vector3& getPosition() const
   {
      return m_position;
   }

   void setPosition(const Vector3& position)
   {
      m_position = position;
   }

   const Vector3& getVelocity() const
   {
      return m_velocity;
   }

   void setVelocity(const Vector3& velocity)
   {
      m_velocity = velocity;
   }

   State operator +(const State& s)
   {
      State state;
      state.setPosition(m_position + s.getPosition());
      state.setVelocity(m_velocity + s.getVelocity());
      return state;
   }

   State operator *(double d)
   {
      State state;
      state.setPosition(m_position * d);
      state.setVelocity(m_velocity * d);
      return state;
   }

private:

   Vector3 m_position;

   Vector3 m_velocity;
};

#endif /* STATE_H_ */
