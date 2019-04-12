#include <GL/freeglut.h>
#include <queue>
#include <algorithm>
#include "graphics/common.h"

#include "labirint.h"
#include "labirint_scanner.h"
#include "labirint_finder.h"

Labirint::Labirint(int rows, int cols, int size) : rows(rows), cols(cols), size(size) {
   e_wall = vvi(rows + 1, vi(cols + 1, 1));
   s_wall = vvi(rows + 1, vi(cols + 1, 1));
   scanner = new LabirintScanner(0, 0, this);
   adj.resize((rows + 1) * (cols + 1));
}

int Labirint::pack(int row, int col) {
   return row * cols + col;
}


void Labirint::drawLabirint() {
   glColor3i(0, 0, 0);
   for (int i = 0; i <= rows; ++i) {
      for (int j = 0; j <= cols; ++j) {
         if (e_wall[i][j] && j != cols) {
            drawLine(dx + i*size, dy + j*size, dx + i * size, dy + (j + 1)*size);
         }
         if (s_wall[i][j] && i != rows) {
            drawLine(dx + i * size, dy + j * size, dx + (i + 1) * size, dy + j*size);
         }
      }
   }
}
void Labirint::draw() {
   if (mode == GEN_LAB) {
      scanner->draw();
   } if (mode == FIND_PATH) {
      finder->draw();
   }
   drawLabirint();
}
bool Labirint::nextGenLab() {
   return scanner->next();
}

bool Labirint::isCorrectCoord(int row, int col) const {
   return (0 <= row && row < rows) && (0 <= col && col < cols);
}

void Labirint::removeWall(int x1, int y1, int x2, int y2) {
   if (x1 == x2) {
      s_wall[x1][std::max(y1, y2)] = 0;
   } else if (y1 == y2) {
      e_wall[std::max(x1, x2)][y1] = 0;
   }
   adj[pack(x1,y1)].push_back(pack(x2, y2));
   adj[pack(x2,y2)].push_back(pack(x1, y1));
}

bool Labirint::isNeighbor(int x1, int y1, int x2, int y2) {
   vi &v = adj[pack(x1, y1)];
   return find(v.begin(), v.end(), pack(x2, y2)) != v.end();
}


void Labirint::findPath() {
   finder = new LabirintFinder(0, 0, rows - 1, cols - 1, this);
   finder->findPath();
}


bool Labirint::nextFind() {
   return finder->next();
}


