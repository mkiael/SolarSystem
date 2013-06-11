#pragma once


class IPlayer
{
public:

   virtual void updateControls(double dt) = 0;
   virtual void updateView() = 0;

};
