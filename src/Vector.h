#pragma once
#include <math.h>

//! @brief  
template <typename T>
class Vector
{
public:

   Vector(T x, T y, T z);

   //! Makes the vector to unit length
   void normalize();
   
   //! Get The length of the vector
   double getLength();

	T x, y, z;
};

