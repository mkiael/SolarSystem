#include "Vector.h"

template <typename T>
Vector<T>::Vector(T x, T y, T z)
: x(x)
, y(x)
, z(z)
{
}

template <typename T>
void Vector<T>::normalize()
{
	double l = getLength(); 
	x = x / l;
	y = y / l;
	z = z / l;
}

template <typename T>
double Vector<T>::getLength()
{
	return sqrt(x*x + y*y + z*z);
}

template class Vector<int>;
template class Vector<double>;