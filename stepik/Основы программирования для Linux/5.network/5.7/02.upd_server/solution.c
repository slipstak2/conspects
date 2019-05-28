#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>


#define BUF_SIZE 5000

int main(int c, char** v) {

    int port = atoi(v[1]);
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in local;
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    bind(s, (struct sockaddr*) &local, sizeof(local));

    while (true) {
        char buf[BUF_SIZE + 1];
        int len = read(s, buf, BUF_SIZE);
        buf[len] = 0;
        if (!strcmp(buf, "OFF\n")) {
            break;
        } else {
            printf("%s\n", buf);
        }
    }
    return 0;
}
