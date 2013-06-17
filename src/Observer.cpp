#include "Observer.h"

Observer::Observer()
: m_camera()
, m_controls()
{
}

void Observer::init()
{
   m_camera.setViewport(0, 0, (GLsizei)500, (GLsizei)500);
   m_camera.setFrustrum(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
}

void Observer::updateControls()
{
   m_controls.update();
}

void Observer::updateView()
{
   // Zoom
   m_camera.setFocus(0.0, 0.0, 20.0 - m_controls.getMouseScroll());

   // Click-hold-rotation
   int rot[3] = {0, 0, 0};
   if(m_controls.isLeftMouseButtonPressed())
   {
      rot[0] = m_controls.getMouseSpeedX();
      rot[1] = m_controls.getMouseSpeedY();
   }

   // hard to figure out without any kind of reference point...background perhaps?:)
   m_camera.alterRotation(0, rot[0], rot[1]);
}
