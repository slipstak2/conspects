#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <cmath>

using namespace std;


class GLintPoint {
public:
   GLint x, y;
};


double f(double x) {
   return cos(2* M_PI * x) / pow(M_E, x);
}
void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);
   GLdouble A, B, C, D;
   int screenWidth  = glutGet(GLUT_WINDOW_WIDTH);
   int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
   A = screenWidth / 4.0;
   B = 0;
   C = screenHeight / 2.0;
   D = C;
   glBegin(GL_POINTS);
      for (GLdouble x = 0; x < 4.0; x += 0.005) {
         glVertex2d(A * x + B, C * f(x) + D);
      }
   glEnd();
   glFlush();
}

void myReshape(int width, int height) {
   printf("Reshape: %d x %d\n", width, height);
}

void myMouse(int button, int state, int x, int y) {
   printf("Mouse: %d x %d\n", x, y);
}

void myKeyboard(unsigned char key, int x, int y) {
   switch (key) {
   case 27:
      exit(0);
   }
}

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(2.0);


   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char* argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(100, 150);
   glutCreateWindow("my first attemp");

   glutDisplayFunc(myDisplay);
   glutReshapeFunc(myReshape);
   glutMouseFunc(myMouse);
   glutKeyboardFunc(myKeyboard);

   myInit();
   glutMainLoop();
   return 0;
}