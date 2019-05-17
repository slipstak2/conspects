#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char command[1024];
    sprintf(command, "./%s %s", argv[1], argv[2]);

    FILE* fp = popen(command, "r");

    const int ROW_SIZE = 1024;
    char row[ROW_SIZE];

    int cnt = 0;
    while (fgets(row, ROW_SIZE, fp) != NULL) {
        int i;
        size_t len = strlen(row);
        for (i = 0; i < len; ++i) {
            if (row[i] == '0') {
                ++cnt;
            }
        }
    }

    printf("%d\n", cnt);

    pclose(fp);
    return 0;
}
