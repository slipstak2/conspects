#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int get_parent_proc_id(int proc_id) {
    char status_path[1024];
    sprintf(status_path, "/proc/%d/status", proc_id);

    const int ROW_SIZE = 1024;
    char row[ROW_SIZE];
    FILE* fp = fopen(status_path, "r");
    int parent_id = -1;
    if (fp) {
        while (!feof(fp)) {
            fgets(row, ROW_SIZE, fp);
            if(strstr(row, "PPid")) {
                sscanf(row, "PPid: %d", &parent_id);
                break;
            }
        }
    }
    fclose(fp);
    return parent_id;
}

int main(int argc, char * argv[]) {
    int proc_id = atoi(argv[1]);
    while (proc_id >= 1) {
        printf("%d\n", proc_id);
        proc_id = get_parent_proc_id(proc_id);
    }
    return 0;
}
