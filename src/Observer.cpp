#include "Observer.h"

Observer::Observer()
{
   glMatrixMode (GL_PROJECTION);

   m_camera.setViewport(0, 0, (GLsizei) 500, (GLsizei) 500);
   m_camera.setFrustrum(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
}

void Observer::updateControls(double dt)
{
   m_controls.update(dt);
}

void Observer::updateView()
{
   // Zoom
   m_camera.setFocus(0.0, 0.0, 20.0 - (double)m_controls.MouseScroll());

   // Click-hold-rotation
   int rot[3] = {0, 0, 0};
   if(m_controls.LeftMouseButton())
   {
      rot[0] = m_controls.mouseXspeed();
      rot[1] = m_controls.mouseYspeed();
   }

   // hard to figure out without any kind of reference point...background perhaps?:)
   m_camera.alterRotation(0, rot[0], rot[1]);
}
