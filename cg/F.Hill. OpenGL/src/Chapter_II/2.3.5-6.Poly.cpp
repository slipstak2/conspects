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
   glPointSize(2.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}


void drawPolygon() {
   glBegin(GL_POLYGON);
      glVertex2i(20, 10);
      glVertex2i(10, 30);
      glVertex2i(30, 50);
      glVertex2i(50, 30);
      glVertex2i(40, 10);
   glEnd();
}

void drawTriangles(int dx, int dy, int mulX, int mulY) {
   glColor3f(0.8, 0.1, 0.15);
   glBegin(GL_TRIANGLES);
      // first triangles
      glVertex2i(dx + mulX * 10, dy + mulY * 10);
      glVertex2i(dx + mulX * 30, dy + mulY * 35);
      glVertex2i(dx + mulX * 50, dy + mulY * 15);

      //second triangles
      glVertex2i(dx + mulX * 70, dy + mulY * 5);
      glVertex2i(dx + mulX * 50, dy + mulY * 30);
      glVertex2i(dx + mulX * 60, dy + mulY * 50);
   glEnd();
}

void drawTrianglesStrip(int dx, int dy, int mulX, int mulY) {
   glColor3f(0.1, 0.15, 0.8);
   glBegin(GL_TRIANGLE_STRIP);
      
      glVertex2i(dx + mulX * 10, dy + mulY * 10);
      glVertex2i(dx + mulX * 30, dy + mulY * 35);
      glVertex2i(dx + mulX * 50, dy + mulY * 15);

      glVertex2i(dx + mulX * 70, dy + mulY * 50);
      glVertex2i(dx + mulX * 90, dy + mulY * 30);
   glEnd();
}

void drawTrianglesFan(int dx, int dy, int mulX, int mulY) {
   glColor3f(0.15, 0.8, 0.1);
   glBegin(GL_TRIANGLE_FAN);
      glVertex2i(dx + mulX * 10, dy + mulY * 10);

      glVertex2i(dx + mulX * 30, dy + mulY * 55);
      glVertex2i(dx + mulX * 50, dy + mulY * 35);
      glVertex2i(dx + mulX * 50, dy + mulY * 15);
   glEnd();
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   drawPolygon();
   drawTriangles(0, 100, 2, 2);
   drawTrianglesStrip(100, 0, 2, 2);
   drawTrianglesFan(150, 150, 2, 2);

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