#include <iostream>


int main() {
   int b[5] = {1, 2, 3};
   // int b[5] = {1, 2, 3, 0, 0}
   for (int i = 0; i < 5; ++i) {
      printf("%d ", b[i]);
   }
   return 0;
}