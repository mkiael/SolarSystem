#include "Controls.h"

Controls::Controls()
 : m_mouseX(0)
 , m_mouseY (0)
{

}

void Controls::update(double dt)
{
   m_mouseXspeed = m_mouseX;
   m_mouseYspeed = m_mouseY;

   glfwGetMousePos(&m_mouseX, &m_mouseY);

   //take diff from last update
   m_mouseXspeed -= m_mouseX;
   m_mouseYspeed -= m_mouseY;
}

int Controls::MouseScroll()
{
   return glfwGetMouseWheel();

}

bool Controls::LeftMouseButton()
{
   return (bool)glfwGetMouseButton( GLFW_MOUSE_BUTTON_LEFT );
}
