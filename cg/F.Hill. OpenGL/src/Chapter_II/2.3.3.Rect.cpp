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

void drawFlurry(int num, int Width, int Height) {
   // num rectangles
   for (int i = 0; i < num; ++i) {
      GLint x1 = random(Width);
      GLint y1 = random(Height);
      GLint x2 = random(Width);
      GLint y2 = random(Height);
      
      GLfloat lev = random(10) / 10.0;
      glColor3f(lev, lev, lev);
      
      glRecti(x1, y1, x2, y2);
      glFlush();
   }
}
void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.6, 0.6, 0.6);
   glRecti(20, 20, 100, 70);

   glColor3f(0.2, 0.2, 0.2);
   glRecti(70, 50, 150, 130);

   drawFlurry(100, screenWidth, screenHeight);

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