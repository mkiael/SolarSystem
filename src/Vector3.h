#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <math.h>

class Vector3
{
public:

   Vector3(double x, double y, double z);

   ~Vector3();

   double getX() const
   {
      return m_x;
   }

   void setX(double x)
   {
      m_x = x;
   }

   double getY() const
   {
      return m_y;
   }

   void setY(double y)
   {
      m_y = y;
   }

   double getZ() const
   {
      return m_z;
   }

   void setZ(double z)
   {
      m_z = z;
   }

   Vector3 operator +(const Vector3& v) const
   {
      return Vector3(m_x + v.getX(), m_y + v.getY(), m_z + v.getZ());
   }

   Vector3 operator -(const Vector3& v) const
   {
      return Vector3(m_x - v.getX(), m_y - v.getY(), m_z - v.getZ());
   }

   Vector3 operator *(double d) const
   {
      return Vector3(m_x * d, m_y * d, m_z * d);
   }

   void normalize()
   {
      double magSq = m_x * m_x + m_y * m_y + m_z * m_z;
      if (magSq > 0.0)
      {
         double oneOverMag = 1.0 / sqrt(magSq);
         m_x *= oneOverMag;
         m_y *= oneOverMag;
         m_z *= oneOverMag;
      }
   }

private:

   double m_x;

   double m_y;

   double m_z;

};

double vectorMag(const Vector3& v);

double distance(const Vector3& p1, const Vector3& p2);

#endif /* VECTOR3_H_ */
