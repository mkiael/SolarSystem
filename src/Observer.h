#pragma once

#include "IPlayer.h"
#include "Camera.h"
#include "Controls.h"

class Observer : public IPlayer
{
public:

   Observer();

   void init();

   void updateControls() ;

   void updateView();

private:

   Camera m_camera;

   Controls m_controls;

};
