#pragma once


class IPlayer
{
public:

   virtual void updateControls() = 0;
   virtual void updateView() = 0;

};
