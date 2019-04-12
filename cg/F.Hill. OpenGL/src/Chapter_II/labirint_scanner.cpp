
#include <algorithm>
#include "labirint_scanner.h"
#include "graphics/common.h"

LabirintScanner::LabirintScanner(int beginRow, int beginCol, Labirint* lab)
   : curRow(beginRow)
   , curCol(beginCol)
   , labirint(*lab)
   , visit(vvi(labirint.rows + 1, vi(labirint.cols + 1, 0)))
   , typeVisit(vvi(labirint.rows + 1, vi(labirint.cols + 1, -1)))
   , timeVisit(0)
{
   visit[curRow][curCol] = timeVisit++;
   way.push(GLintPoint(curRow, curCol));
}

bool LabirintScanner::isFree(int row, int col) const {
   if (labirint.isCorrectCoord(row, col)) {
      return !visit[row][col];
   }
   return false;
}

bool LabirintScanner::next() {
   static std::vector<int> pos;
   pos.clear();
   for (int i = 0; i < 4; ++i) {
      int nxtRow = curRow + moveX[i];
      int nxtCol = curCol + moveY[i];
      if (isFree(nxtRow, nxtCol)) {
         pos.push_back(i);
      }
   }
   if (pos.size() == 0) {
      visit[curRow][curCol] = timeVisit++;
      typeVisit[curRow][curCol] = OUTSIDE;
      if (way.empty()) {
         return false;
      }
      curRow = way.top().x;
      curCol = way.top().y;
      way.pop();
      return true;
   }
   int nxtPos = random(pos.size());
   int nxtRow = curRow + moveX[pos[nxtPos]];
   int nxtCol = curCol + moveY[pos[nxtPos]];
   labirint.removeWall(curRow, curCol, nxtRow, nxtCol);

   visit[nxtRow][nxtCol] = timeVisit++;
   typeVisit[nxtRow][nxtCol] = INSIDE;

   curRow = nxtRow;
   curCol = nxtCol;
   way.push(GLintPoint(curRow, curCol));
   return true;
}


void LabirintScanner::setCellColor(int row, int col, float dcolor) {
   float r = 0.5;
   float g = 0.5;
   float b = 0.5;
   if (row == curRow && col == curCol) {
      glColor3f(0.0, 0.0, 0.0);
      return;
   }
   r = 255.0, g = 106.0, b = 0.0; // orange;

   glColor3f(
      std::min(r + dcolor, 255.0f) / 255.0,
      std::min(g + dcolor, 255.0f) / 255.0,
      std::min(b + dcolor, 255.0f) / 255.0
   );
}

void LabirintScanner::draw() {
   for (int i = 0; i <= labirint.rows; ++i) {
      for (int j = 0; j <= labirint.cols; ++j) {
         if (visit[i][j]) {
            float dcolor = (timeVisit - visit[i][j]) / 5;
            setCellColor(i, j, dcolor);
            glRecti(
               dx + i * labirint.size,
               dy + j * labirint.size,
               dx + (i + 1) * labirint.size,
               dy + (j + 1) * labirint.size
            );
         }
      }
   }
}
