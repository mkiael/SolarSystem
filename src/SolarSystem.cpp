#include "SolarSystem.h"
#include "GL/glfw.h"

SolarSystem::SolarSystem()
: m_celestialBodies()
{
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::draw()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   for (ICelestialBodySP spCelestialBody : m_celestialBodies)
   {
      spCelestialBody->draw();
   }

   glfwSwapBuffers();
}

void SolarSystem::addCelestialBody(const ICelestialBodySP& spCelestialBody)
{
   m_celestialBodies.push_back(spCelestialBody);
}
