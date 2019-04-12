#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"
#include <time.h>
#include "labirint.h"


#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;


typedef vector<int> vi;
typedef vector<vi>  vvi;

const int screenWidth = 768;
const int screenHeight = 480;


const int CELL_SIZE = 4;
Labirint lab((screenWidth - 2 * dx) / CELL_SIZE, (screenHeight - 2 * dy) / CELL_SIZE , CELL_SIZE);
//Labirint lab(4, 4, CELL_SIZE);

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(5.0);
   glLineWidth(1.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

   glClear(GL_COLOR_BUFFER_BIT);
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);
   lab.draw();
   if (lab.mode == GEN_LAB) {
      if (lab.nextGenLab()) {
         glutPostRedisplay();
         //Sleep(1);
      } else {
         lab.mode = FIND_PATH;
         Sleep(100);
         lab.findPath();
         glutPostRedisplay();
      }
   } else if (lab.mode == FIND_PATH) {
      if (lab.nextFind()) {
         glutPostRedisplay();
      }      
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
   case 32:
      lab.mode = GEN_LAB;
      glutPostRedisplay();
      break;
   case 27:
      exit(0);
   }
}

int main(int argc, char* argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(screenWidth, screenHeight);
   glutInitWindowPosition(100, 150);
   glutCreateWindow("labyrinth generation (press SPACE)");

   glutDisplayFunc(myDisplay);
   glutReshapeFunc(myReshape);
   glutMouseFunc(myMouse);
   glutMotionFunc(myMovedMouse);
   glutKeyboardFunc(myKeyboard);

   myInit();
   glutMainLoop();
   return 0;
}