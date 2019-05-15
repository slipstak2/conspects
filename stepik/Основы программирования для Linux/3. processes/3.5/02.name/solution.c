#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <stdbool.h>

bool is_number(char* s) {
    char *c;
    for (c = s; *c; ++c) {
        if (!isdigit(*c)) {
            return false;
        }
    }
    return true;
}

bool check_proc_name(const char *root, const char *proc_id, const char *target_proc_name) {
    char status_path[1024];
    sprintf(status_path, "%s/%s/status", root, proc_id);
    FILE *fp = fopen(status_path, "r");
    
    const int ROW_SIZE = 1024;
    char row[ROW_SIZE];
    
    bool isOK = false;
    while (!feof(fp)) {
        fgets(row, ROW_SIZE, fp);
        if (strstr(row, "Name:")) {
            char proc_name[1024];
            sscanf(row, "Name:\t%s", proc_name);
            isOK = !strcmp(proc_name, target_proc_name);
        }
    }
    fclose(fp);
    return isOK;
}

int search(const char* root, const char* proc_name) {
    int cnt = 0;
    struct dirent **namelist;
    int n = scandir(root, &namelist, NULL, alphasort);
    if (n >= 0) {
        while(n--) {
            if (is_number(namelist[n]->d_name)) {
                if (check_proc_name(root, namelist[n]->d_name, proc_name)) {
                    cnt++;
                }
            }
            free(namelist[n]);
        }
    }
    return cnt;
}

int main() {
    printf("%d\n", search("/proc", "genenv"));
    return 0;
}
