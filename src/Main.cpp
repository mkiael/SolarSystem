#include <GL/glfw.h>
#include "ISolarSystem.h"
#include "BigBang.h"
#include "Observer.h"

Observer *pPlayer;

void init()
{

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);

   GLfloat model_ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);  //Background light

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   //glEnable(GL_COLOR_MATERIAL); // Why does this need to be off for materials to work!?!?

   //Camera Settings
   pPlayer = new Observer();
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

      pPlayer->updateControls(delta);
      pPlayer->updateView();

      spSolarSystem->simulate();
      spSolarSystem->render();

      glfwSwapBuffers();

      isRunning = !glfwGetKey(GLFW_KEY_ESC);
   }

   return 0;
}
