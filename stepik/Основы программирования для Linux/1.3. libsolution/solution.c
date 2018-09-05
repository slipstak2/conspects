#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

int (*f) (int);

bool init_library(const char* libName, const char* funcName) {
	void *hdl = dlopen(libName, RTLD_LAZY);
	if (NULL == hdl) {
		printf("Library not found\n");
		return false;
	}
	f = (int (*) (int))dlsym(hdl, funcName);
	if (NULL == f) {
		printf("Function not found\n");
		return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	const char* libName = argv[1];
	const char* funcName = argv[2];
	int intParam = atoi(argv[3]);
        // printf("%s\n%s\n%s\n", argv[1], argv[2], argv[3]);
	if (init_library(libName, funcName)) {
		printf("%d\n", f(intParam));
	} else {
		printf("Error on init_library\n");
	}
	return 0;
}
