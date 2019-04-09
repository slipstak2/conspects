#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A, B, C, D;

void myInit() {
   // background color: white
   glClearColor(1.0, 1.0, 1.0, 0.0);

   // drawing color: black
   glColor3f(0.0, 0.0, 0.0);
   glPointSize(2.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

   A = screenWidth / 4.0;
   B = 0.0;
   C = D = screenHeight / 2.0;
}


void drawPolyLineFile(char* fileName) {
   fstream inStream;
   inStream.open(fileName, ios::in);
   if (inStream.fail()) {
      return;
   }
   glClear(GL_COLOR_BUFFER_BIT);
   GLint numpolys, numLines, x, y;
   inStream >> numpolys;
   for (int j = 0; j < numpolys; ++j) {
      inStream >> numLines;
      glBegin(GL_LINE_STRIP);
         for (int i = 0; i < numLines; ++i) {
            inStream >> x >> y;
            glVertex2i(x, y);
         }
      glEnd();
   }
   glFlush();
   inStream.close();
}

void myDisplay()
{
   drawPolyLineFile("../../../data/dino.dat");
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