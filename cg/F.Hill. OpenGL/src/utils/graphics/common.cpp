#include "common.h"

void drawDot(GLint x, GLint y) {
   glBegin(GL_POINTS);
      glVertex2i(x, y);
   glEnd();
}

void drawLine(GLint x1, GLint y1, GLint x2, GLint y2) {
   glBegin(GL_LINES);
      glVertex2i(x1, y1);
      glVertex2i(x2, y2);
   glEnd();
}

int random(int x) {
   return rand() % x;
}