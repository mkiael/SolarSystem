#include "Controls.h"
#include <GL/glfw.h>

Controls::Controls()
: m_mouseX(0)
, m_mouseY (0)
, m_mouseSpeedX(0)
, m_mouseSpeedY(0)
{

}

void Controls::update()
{
   m_mouseSpeedX = m_mouseX;
   m_mouseSpeedY = m_mouseY;

   glfwGetMousePos(&m_mouseX, &m_mouseY);

   //take diff from last update
   m_mouseSpeedX -= m_mouseX;
   m_mouseSpeedY -= m_mouseY;
}

double Controls::getMouseScroll()
{
   return (double)glfwGetMouseWheel();
}

bool Controls::isLeftMouseButtonPressed()
{
   return glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}
