#pragma once

class Controls
{
public:

   Controls();

   int getMouseSpeedX()
   {
      return m_mouseSpeedX;
   }

   int getMouseSpeedY()
   {
      return m_mouseSpeedY;
   }

   double getMouseScroll();

   bool isLeftMouseButtonPressed();

   void update();

private:

   int m_mouseX;

   int m_mouseY;

   int m_mouseSpeedX; //diff between this and last position

   int m_mouseSpeedY; //diff between this and last position

};
