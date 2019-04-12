#pragma once
#include <GL/glut.h>

void drawDot(GLint x, GLint y);
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2);
int random(int x);

class GLintPoint {
public:
   GLintPoint() : x(0), y(0){}
   GLintPoint(int x, int y) : x(x), y(y) {}
public:
   GLint x, y;
};