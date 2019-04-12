#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


const int screenWidth  = 640;
const int screenHeight = 480;

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(2.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}


void drawRects(int size, int isEven) {
   for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
         if ((i + j) % 2 == isEven) {
            glRecti(i*size, j*size, (i+1)*size, (j+1)*size);
         }
      }
   }
}
void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   int size = min(screenHeight, screenWidth) / 8;
   glColor3f(0.6, 0.6, 0.6);
   drawRects(size, 0);

   glColor3f(0.2, 0.2, 0.2);
   drawRects(size, 1);

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

int main(int argc, char* argv[]) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(screenWidth, screenHeight);
   glutInitWindowPosition(100, 150);
   glutCreateWindow("dot plot of a function");

   glutDisplayFunc(myDisplay);
   glutReshapeFunc(myReshape);
   glutMouseFunc(myMouse);
   glutKeyboardFunc(myKeyboard);

   myInit();
   glutMainLoop();
   return 0;
}