#include "GL/freeglut.h"
#include "graphics/common.h"

#include <iostream>

using namespace std;


class GLintPoint {
public:
      GLint x, y;
};

int random(int m) {
   return rand() % m;
}

void Sierpinski() {

   GLintPoint T[3] = {{10, 10}, {500, 30}, {300, 450}};
   int index = random(3);

   GLintPoint point = T[index];
   drawDot(point.x, point. y);
   for (int i = 0; i < 100000; ++i) {
      index = random(3);
      point.x = (point.x + T[index].x) / 2;
      point.y = (point.y + T[index].y) / 2;
      drawDot(point.x, point.y);
   }
   glFlush();
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);
   Sierpinski();
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
   glPointSize(1.0);


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