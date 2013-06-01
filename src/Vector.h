#pragma once
#include <math.h>

//! @brief  
class Vector
{
public:

   Vector(double x, double y, double z);

   //! Makes the vector to unit length
   void normalize();
   
   //! Get The length of the vector
   double getLength();

   double x, y, z;
};

