/*
/home/bi/CLionProjects/mail_ru_deep_c/cmake-build-debug/mail_ru_deep_c

L1d cache line size is 64
p and &p are 0x1350040 and 0x7fffaca5ab78

Process finished with exit code 0
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // memcpy

int main() {
    int b[7] = {1, [5] = 10, 20,[1] = 2}; // массив-источник
    int *p = NULL,                        // массив-приемник
    errflag;                          // код ошибки posix_memaling

    // установить размер линии кэш-памяти данных 1го уровня
    // (L1d); типичное значение: 64 байта
    long l1dcls = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    // проверить, удался ли вызов sysconf()
    if (l1dcls == -1)
    // если вызов sysconf() неудачен, использовать значение
    // выравнивания по умолчанию
      l1dcls = sizeof(void*);
    // выделить память с выравниваем на границу строки L1d
    errflag = posix_memalign((void**)&p, l1dcls, sizeof b);
    if (!errflag) // в случае успеха posix_memalign возвращает 0
    {
      printf("\nL1d cache line size is %ld\n", l1dcls);
      printf("p and &p are %p and %p\n", p, &p);
      p = memcpy(p, b, sizeof(b));
      //...
      free(p);
    }
    else
      printf("posix_memalign error: %d\n", errflag);

    return 0;
}