#include "Vector.h"


Vector::Vector(double x, double y, double z)
: x(x)
, y(x)
, z(z)
{
}

void Vector::normalize()
{
	double l = getLength(); 
	x = x / l;
	y = y / l;
	z = z / l;
}

double Vector::getLength()
{
	return sqrt(x*x + y*y + z*z);
}
