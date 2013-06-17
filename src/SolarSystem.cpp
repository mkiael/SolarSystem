#include "SolarSystem.h"
#include "Vector3.h"
#include "GL/glfw.h"

static const double G = 6.674e-11;
static const double dt = 0.01;

SolarSystem::SolarSystem()
: m_celestialBodies()
, m_time(0.0)
, m_currentTime(0.0)
, m_newTime(0.0)
, m_frameTime(0.0)
, m_accumulator(0.0)
{
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::simulate()
{
   double newTime = glfwGetTime();
   double frameTime = newTime - m_currentTime;
   m_currentTime = newTime;

   if (frameTime > 0.25)
   {
      frameTime = 0.25;
   }

   m_accumulator += frameTime;

   while (m_accumulator >= dt)
   {
      auto spSun = m_celestialBodies[0];
      auto sunState = spSun->getState();
      for (unsigned int i = 1; i < m_celestialBodies.size(); ++i)
      {
         auto spBody = m_celestialBodies[i];
         auto bodyState = spBody->getState();

         Vector3 r = sunState.getPosition() - bodyState.getPosition();

         double rMag = vectorMag(r);

         Vector3 f = r * ((G * spSun->getMass() * spBody->getMass()) / (rMag*rMag*rMag));

         spBody->simulate(f, m_time, dt);
      }

      m_time += dt;
      m_accumulator -= dt;
   }
}

void SolarSystem::render()
{
   const double alpha = m_accumulator / dt;

   for (auto spCelestialBody : m_celestialBodies)
   {
      spCelestialBody->render(alpha);
   }
}

void SolarSystem::addCelestialBody(const ICelestialBodySP& spCelestialBody)
{
   m_celestialBodies.push_back(spCelestialBody);
}
