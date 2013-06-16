#pragma once

#include <GL/gl.h>
#include <GL/glfw.h>

#include "IPlayer.h"
#include "Camera.h"
#include "Controls.h"

class Observer :IPlayer
{
public:
   Observer();

   void updateControls(double dt) ;
   void updateView();
   Camera m_camera;
   Controls m_controls;

};
