#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return *(char*)b - *(char*)a;
}

int main(int c, char** v) {
    int port = atoi(v[1]);
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in local;
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    bind(ss, (struct sockaddr*) &local, sizeof(local));
    listen(ss, 5);
    int cs = accept(ss, NULL, NULL);
    while (true) {
        char buf[BUFSIZ];
        int len = read(cs, buf, BUFSIZ);
        buf[len] = 0;
        if (!strcmp(buf, "OFF\n")) {
            break;
        } else {
            qsort(buf, strlen(buf), 1, cmp);
            write(cs, buf, strlen(buf) + 1);
            //printf("%s\n", buf);
        }
    }


    return 0;
}
