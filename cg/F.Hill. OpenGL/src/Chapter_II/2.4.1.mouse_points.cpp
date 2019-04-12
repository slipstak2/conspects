#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <cmath>

using namespace std;


const int screenWidth  = 640;
const int screenHeight = 480;

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(5.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

   glClear(GL_COLOR_BUFFER_BIT);
}

void myDisplay()
{
  // glClear(GL_COLOR_BUFFER_BIT);

   glFlush();
}

void myReshape(int width, int height) {
   printf("Reshape: %d x %d\n", width, height);
}

void myMouseInfo(int button, int state, int x, int y) {
   string buttonStr;
   switch (button) {
   case GLUT_LEFT_BUTTON: buttonStr = "LEFT_BUTTON";
      break;
   case GLUT_RIGHT_BUTTON: buttonStr = "RIGHT_BUTTON";
      break;
   case GLUT_MIDDLE_BUTTON: buttonStr = "MIDDLE_BUTTON";
      break;
   }

   string stateStr;
   switch (state) {
   case GLUT_UP:  stateStr = "UP";
      break;
   case GLUT_DOWN: stateStr = "DOWN";
      break;
   }

   printf("%s-%s: %d x %d\n", buttonStr.c_str(), stateStr.c_str(), x, y);
}

void myMouse(int button, int state, int x, int y) {
   myMouseInfo(button, state, x, y);

   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      drawDot(x, screenHeight - y);
   } else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
      exit(-1);
   }
   glFlush();
}

void myKeyboard(unsigned char key, int x, int y) {
   switch (key) {
   case 27:
      exit(0);
   }
}

int main(int argc, char* argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(screenWidth, screenHeight);
   glutInitWindowPosition(100, 150);
   glutCreateWindow("mouse functions");

   glutDisplayFunc(myDisplay);
   glutReshapeFunc(myReshape);
   glutMouseFunc(myMouse);
   glutKeyboardFunc(myKeyboard);

   myInit();
   glutMainLoop();
   return 0;
}