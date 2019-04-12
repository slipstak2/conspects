#pragma once

#include <vector>
#include <stack>

#include "labirint.h"
#include "graphics/common.h"

class Labirint;

class LabirintScanner {
   friend class Labirint;
public:
   LabirintScanner(int beginRow, int beginCol, Labirint* lab);
   bool next();

   bool isFree(int row, int col) const;
   void setCellColor(int row, int col, float dcolor);
   void draw();
private:
   int curRow;
   int curCol;
   Labirint& labirint;
   std::stack<GLintPoint> way;

   vvi visit;
   vvi typeVisit;
   int timeVisit = 0;
};
