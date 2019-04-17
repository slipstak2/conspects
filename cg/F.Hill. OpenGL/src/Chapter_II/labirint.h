#pragma once
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi>  vvi;

const int dx = 10;
const int dy = 10;

enum CELL_TYPE {
   INSIDE  = 1,
   OUTSIDE = 2
};

enum LABIRINT_MODE {
   INIT = 0,
   GEN_LAB = 1,
   FIND_PATH = 2
};

enum EDGE_TYPE {
   EAST = 0,
   SOUTH = 1
};

const int moveX[4] = { -1, 0, 1, 0 };
const int moveY[4] = { 0, -1, 0, 1 };



class Labirint {
   friend class LabirintScanner;
   friend class LabirintFinder;
public:
   Labirint(int rows, int cols, int size);
   int pack(int row, int col);

   void draw();
   void drawCell(int row, int col, EDGE_TYPE etype);
   void drawLabirint();

   bool nextGenLab();


   bool isCorrectCoord(int row, int col) const;
   void removeWall(int x1, int y1, int x2, int y2);

   void findPath();
   bool nextFind();

   bool isNeighbor(int x1, int y1, int x2, int y2);

public:
   LABIRINT_MODE mode = INIT;

private:
   int rows;
   int cols;
   int size;
   LabirintScanner* scanner = nullptr;
   LabirintFinder*  finder = nullptr;

   vvi e_wall;
   vvi s_wall;
   vvi adj;


};