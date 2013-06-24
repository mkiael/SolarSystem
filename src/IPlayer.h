#pragma once

#include <memory>

class IPlayer
{
public:

   virtual void init() = 0;

   virtual void update() = 0;

};

typedef std::shared_ptr<IPlayer> IPlayerSP;
