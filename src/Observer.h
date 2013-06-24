#pragma once

#include "IPlayer.h"
#include "Camera.h"

class Observer : public IPlayer
{
public:

   Observer();

   void init();

   void update();

private:

   Camera m_camera;

};
