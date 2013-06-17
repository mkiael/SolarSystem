#pragma once

#include <GL/glfw.h>
#include "Vector3.h"

class Camera
{
public:

   Camera();

   void setViewport(int x, int y, unsigned width, unsigned height);

   void setFocus(double x, double y, double z);

   void setFrustrum(  double left, double right, double bottom, double top, double nearVal, double farVal);

   void setRotation(double x, double y, double z);

   void alterRotation(double dx, double dy, double dz);

private:

   Vector3 m_rotation;

};
