lib:	solution.c
	gcc -shared solution.c -fPIC -o libsolution.so

exe:	main.c solution.h lib
	gcc main.c -fPIC -L. -lsolution -o main
clear:
	rm -f *.o
	rm -f *.so
