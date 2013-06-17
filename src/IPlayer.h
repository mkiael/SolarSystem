#pragma once

#include <memory>

class IPlayer
{
public:

   virtual void init() = 0;

   virtual void updateControls() = 0;

   virtual void updateView() = 0;

};

typedef std::shared_ptr<IPlayer> IPlayerSP;
