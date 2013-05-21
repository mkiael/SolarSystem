#include "TestPlanet.h"
#include "Spheroid.h"

TestPlanet::TestPlanet()
{
	m_sphere = new Spheroid(2, 5, 10);
}

TestPlanet::~TestPlanet()
{
}

void TestPlanet::draw()
{
   m_sphere->draw(0.,0.,0.);
}
