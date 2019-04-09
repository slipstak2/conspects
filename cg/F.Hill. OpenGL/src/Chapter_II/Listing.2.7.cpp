#define _USE_MATH_DEFINES

#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>
#include <cmath>

using namespace std;


const int screenWidth  = 640;
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

void glPoints() {
   glBegin(GL_POINTS);
   for (GLdouble x = 0; x < 4.0; x += 0.005) {
      GLdouble func = exp(-x) * cos(2 * M_PI * x);
      glVertex2d(A * x + B, C * func + D);
   }
   glEnd();
}

void glLines() {
   glLineWidth(4.0);
   glBegin(GL_LINES);
   // horizontal line #1
   glVertex2i(10, 20);
   glVertex2i(40, 20);

   // vertical line #1
   glVertex2i(20, 10);
   glVertex2i(20, 40);

   // horizontal line #2
   glVertex2i(10, 30);
   glVertex2i(40, 30);

   // vertical line #1
   glVertex2i(30, 10);
   glVertex2i(30, 40);
   glEnd();
}

void glLineStrip(int dx, int dy, int mode) {
   glBegin(mode); // GL_LINE_STRIP or GL_LINE_LOOP
      glVertex2i(dx + 20, dy + 10);
      glVertex2i(dx + 50, dy + 10);
      glVertex2i(dx + 20, dy + 80);
      glVertex2i(dx + 50, dy + 80);
   glEnd();
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glPoints();
   glLines();
   glLineStrip(20, 0, GL_LINE_STRIP);
   glLineStrip(60, 0, GL_LINE_LOOP);

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