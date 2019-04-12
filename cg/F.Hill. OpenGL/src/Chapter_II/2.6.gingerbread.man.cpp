#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


const int screenWidth  = 640;
const int screenHeight = 480;

static vector<GLintPoint> List;

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(3.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

   glClear(GL_COLOR_BUFFER_BIT);
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   int M = 40, L = 3;

   glColor3f(0.8, 0.2, 0.15);
   GLintPoint p(115, 121);
   for (int i = 0; i < 100000; ++i) {
      int x = M * (1 + 2 * L) - p.y + abs(p.x - L * M);
      int y = p.x;
      drawDot(p.x, p.y);
      p.x = x;
      p.y = y;
   }

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
}

void myMovedMouse(int mouseX, int mouseY) {
}

void myKeyboard(unsigned char key, int mouseX, int mouseY) {
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
   glutCreateWindow("gingerbread man");

   glutDisplayFunc(myDisplay);
   glutReshapeFunc(myReshape);
   glutMouseFunc(myMouse);
   glutMotionFunc(myMovedMouse);
   glutKeyboardFunc(myKeyboard);

   myInit();
   glutMainLoop();
   return 0;
}