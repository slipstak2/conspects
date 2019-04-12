#pragma once
#include "labirint.h"
#include "graphics/common.h"

class LabirintFinder {
   friend class Labirint;
public:
   LabirintFinder(int beginR, int beginC, int endR, int endC, Labirint* lab);
   
   bool next();

   void findPath();
   
   void setCellColor(int row, int col);
   void draw();
private:
   int beginR;
   int beginC;
   int endR;
   int endC;

   int curRow;
   int curCol;

   Labirint& labirint;
   vvi dst;
   vvi isWay;
};