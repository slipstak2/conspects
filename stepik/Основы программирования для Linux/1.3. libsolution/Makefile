exe:	solution.c
	gcc solution.c -ldl -o solution -Wl,-rpath=.

lib:	shared.c
	gcc -shared shared.c -FPIC -o libShared.so
	
clean:
	rm -f *.o
	rm -f *.so
