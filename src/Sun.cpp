#include "Sun.h"

Sun::Sun()
: m_sphere(4, 10, 20)
{
}

Sun::~Sun()
{
}

void Sun::draw(double delta)
{
   m_sphere.draw(0.0f, 0.0f, 0.0f);
}
