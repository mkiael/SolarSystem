#include <GL/glfw.h>
#include "ISolarSystem.h"
#include "BigBang.h"

void init()
{

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);


   GLfloat model_ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   //glEnable(GL_COLOR_MATERIAL); // Why does this need to be off for materials to work!?!?

   glViewport (0, 0, (GLsizei) 500, (GLsizei) 500);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glfwInit();

   glfwOpenWindow(500, 500, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

   init();

   ISolarSystemSP spSolarSystem(BigBang::bang());

   bool isRunning = true;
   while (isRunning)
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

      spSolarSystem->simulate();
      spSolarSystem->render();

      glfwSwapBuffers();

      isRunning = !glfwGetKey(GLFW_KEY_ESC);
   }

   return 0;
}
