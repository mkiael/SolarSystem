#pragma once

#include <GL/gl.h>
#include <GL/glfw.h>

class Controls
{
public:
   Controls();

   //m Mouse Controls
   int mouseX(){ return m_mouseX;}
   int mouseY(){ return m_mouseY;}
   int mouseXspeed(){ return m_mouseXspeed;}
   int mouseYspeed(){ return m_mouseYspeed;}
   int MouseScroll();
   bool LeftMouseButton();


   void update(double dt);

private:
   int m_mouseX, m_mouseY;
   int m_mouseXspeed, m_mouseYspeed; //diff between this and last position

};
