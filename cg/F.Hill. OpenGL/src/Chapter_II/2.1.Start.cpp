#include "GL/freeglut.h"

#include <iostream>

using namespace std;

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_POINTS);
      glVertex2i(100, 50);
      glVertex2i(100, 130);
      glVertex2i(150, 130);
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
   glPointSize(4.0);


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