#include "TestPlanet.h"

TestPlanet::TestPlanet()
: m_quad(gluNewQuadric())
{
}

TestPlanet::~TestPlanet()
{
}

void TestPlanet::draw()
{
   gluSphere(m_quad, 2.0, 12, 12);
}
