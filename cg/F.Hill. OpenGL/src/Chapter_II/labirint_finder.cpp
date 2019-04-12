#include <queue>
#include <cassert>
#include "labirint_finder.h"


LabirintFinder::LabirintFinder(int beginR, int beginC, int endR, int endC, Labirint* lab)
   : beginR(beginR)
   , beginC(beginC)
   , endR(endR)
   , endC(endC)
   , labirint(*lab)
   , dst(labirint.rows + 1, vi(labirint.cols + 1, 0))
   , isWay(labirint.rows + 1, vi(labirint.cols + 1, 0))
{
   isWay[beginR][beginC] = 1;
}


void LabirintFinder::setCellColor(int row, int col) {
   float r = 0.5;
   float g = 0.5;
   float b = 0.5;

   if (row == curRow && col == curCol) {
      glColor3f(0.0, 0.0, 0.0);
      return;
   }
   if (isWay[row][col] ) {
      r = 0, g = 149.0, b = 255.0; // blue;
   }

   glColor3f(
      r / 255.0,
      g / 255.0,
      b / 255.0
   );
}

void LabirintFinder::findPath() {
   
   int beginX = endR;
   int beginY = endC;

   int endX = beginR;
   int endR = beginC;

   std::queue<GLintPoint> q;
   dst[beginX][beginY] = 1;
   q.push(GLintPoint(beginX, beginY));

   while (!q.empty()) {
      GLintPoint cur = q.front(); q.pop();
      for (int i = 0; i < 4; ++i) {
         int nextX = cur.x + moveX[i];
         int nextY = cur.y + moveY[i];
         if (labirint.isCorrectCoord(nextX, nextY) && !dst[nextX][nextY]) {
            if (labirint.isNeighbor(cur.x, cur.y, nextX, nextY)) {
               dst[nextX][nextY] = dst[cur.x][cur.y] + 1;
               q.push(GLintPoint(nextX, nextY));
            }
         }
      }
   }
   assert(dst[endR][endC]);

   curRow = beginR;
   curCol = beginC;
}

bool LabirintFinder::next() { 
   if (curRow == endR && curCol == endC) {
      return false;
   }
   for (int i = 0; i < 4; ++i) {
      int nxtRow = curRow + moveX[i];
      int nxtCol = curCol + moveY[i];
      if (labirint.isCorrectCoord(nxtRow, nxtCol) && labirint.isNeighbor(curRow, curCol, nxtRow, nxtCol)) {
         if (dst[curRow][curCol] == dst[nxtRow][nxtCol] + 1) {
            curRow = nxtRow;
            curCol = nxtCol;
            isWay[curRow][curCol] = 1;
            return true;
         }
      }
   }
   return false;
}

void LabirintFinder::draw() {
   for (int i = 0; i <= labirint.rows; ++i) {
      for (int j = 0; j <= labirint.cols; ++j) {
         if (isWay[i][j]) {
            setCellColor(i, j);
            glRecti(
               dx + i * labirint.size,
               dy + j * labirint.size,
               dx + (i + 1) * labirint.size,
               dy + (j + 1) * labirint.size
            );
         }
      }
   }
   Sleep(10);
}
