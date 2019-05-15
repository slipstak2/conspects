#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX_PROC_CNT = 10000;

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

bool is_number(char* s) {
    char *c;
    for (c = s; *c; ++c) {
        if (!isdigit(*c)) {
            return false;
        }
    }
    return true;
}

void scan_proc(const char* root, int *_ppid) {
    struct dirent **namelist;
    int n = scandir(root, &namelist, NULL, alphasort);
    if (n >= 0) {
        while(n--) {
            if (is_number(namelist[n]->d_name)) {
                int proc_id = atoi(namelist[n]->d_name);
                _ppid[proc_id] = get_parent_proc_id(proc_id);
            }
            free(namelist[n]);
        }
    }
}

int dfs(int proc_id, int* _ppid){
    int cnt = 1;
    int cur_pid;
    for (cur_pid = 0; cur_pid < MAX_PROC_CNT; ++cur_pid) {
        if (_ppid[cur_pid] == proc_id) {
            cnt += dfs(cur_pid, _ppid);
        }
    }
    return cnt;
}

int main(int argc, char* argv[]) {
    int _ppid[MAX_PROC_CNT];
    memset(_ppid, -1, sizeof(_ppid));

    scan_proc("/proc", _ppid);

    printf("%d\n", dfs(atoi(argv[1]), _ppid));
    return 0;      
}
