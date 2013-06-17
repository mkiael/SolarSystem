#include "Camera.h"

Camera::Camera()
: m_rotation(0.0, 0.0, 0.0)
{
}

void Camera::setViewport(int x, int y, unsigned width, unsigned height)
{
   glViewport(x, y, width, height);
}

void Camera::setFrustrum(double left,
                         double right,
                         double bottom,
                         double top,
                         double nearVal,
                         double farVal)
{
   glFrustum(left, right, bottom, top, nearVal, farVal);

}

void Camera::alterRotation(double dx, double dy, double dz)
{
   m_rotation.setX(m_rotation.getX()+dx);
   m_rotation.setY(m_rotation.getY()+dy);
   m_rotation.setZ(m_rotation.getZ()+dz);
   setRotation(m_rotation.getX(), m_rotation.getY(), m_rotation.getZ());
}

void Camera::setRotation(double x, double y, double z)
{
   glRotatef(m_rotation.getX(), 1.f, 0.f, 0.f); // orbit the X axis
   glRotatef(m_rotation.getY(), 0.f, 1.f, 0.f); // orbit the Y axis
   glRotatef(m_rotation.getZ(), 0.f, 0.f, 1.f); // orbit the Z axis
}

void Camera::setFocus(double x, double y, double z)
{
   gluLookAt(x, y, z,    // look from camera XYZ
             0, 0, 0,    // look at the origin
             0, 1, 0);   // positive Y up vector
}
