#include "Camera.h"
#include "Vector3.h"

Camera::Camera()
{
   m_pRotation = new Vector3(0.0, 0.0, 0.0);
   glLoadIdentity();

}

void Camera::setViewport(int x, int y, unsigned width, unsigned height)
{
   glViewport (x, y, width, height);
}

void Camera::setFrustrum(  double left,
                              double right,
                              double bottom,
                              double top,
                              double nearVal,
                              double farVal)
{
   glFrustum ( left, right, bottom, top, nearVal, farVal);

}

void Camera::alterRotation(double dx, double dy, double dz)
{
   m_pRotation->setX(m_pRotation->getZ()+dx);
   m_pRotation->setY(m_pRotation->getY()+dy);
   m_pRotation->setZ(m_pRotation->getZ()+dz);

   setRotation(m_pRotation->getX(), m_pRotation->getY(), m_pRotation->getZ());

}


void Camera::setRotation(double x, double y, double z)
{
   glRotatef(m_pRotation->getX(), 1.f, 0.f, 0.f);/* orbit the X axis */
   glRotatef(m_pRotation->getY(), 0.f, 1.f, 0.f);/* orbit the Y axis */
   glRotatef(m_pRotation->getZ(), 0.f, 0.f, 1.f);/* orbit the Z axis */
}

void Camera::setFocus(double x, double y, double z)
{
   gluLookAt(  x, y, z, /* look from camera XYZ */
               0, 0, 0, /* look at the origin */
               0, 1, 0); /* positive Y up vector */
}
