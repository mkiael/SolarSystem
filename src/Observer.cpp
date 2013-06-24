#include "Observer.h"

Observer::Observer()
: m_camera()
{
}

void Observer::init()
{

}

void Observer::update()
{
   // hard to figure out without any kind of reference point...background perhaps?:)
   m_camera.tick();
}
