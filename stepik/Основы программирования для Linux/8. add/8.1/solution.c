#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>

int main(int c, char **v) {
    struct option opts[] = {
        {"query", optional_argument | required_argument, 0, 'q'},
        {"longinformationrequest", optional_argument, 0, 'i'},
        {"version", optional_argument, 0, 'v'}
    };

    int opindex = 0;
    int opchar = 0;
    bool isOK = true;
    while ( -1 != (opchar = getopt_long(c, v, "q:iv", opts, &opindex))) {
        switch(opchar) {
            case 0:
                break;
            case 'q':
                break;
            case 'i':
                break;
            case 'v':
                break;
            case '?':
                isOK = false;
            default:
                isOK = false;
        }
    }
    printf((isOK ? "+\n" : "-\n"));
    return 0;
}
