#include <GL/glfw.h>
#include "ISolarSystem.h"
#include "BigBang.h"

void init()
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0  };
   GLfloat mat_shininess[] = { 50.0  };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0  };

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

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
   double oldTime = glfwGetTime();
   while (isRunning)
   {
      double newTime = glfwGetTime();
      double delta = newTime - oldTime;
      oldTime = newTime;

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

      spSolarSystem->draw(delta*10.0);

      glfwSwapBuffers();

      isRunning = !glfwGetKey(GLFW_KEY_ESC);
   }

   return 0;
}
