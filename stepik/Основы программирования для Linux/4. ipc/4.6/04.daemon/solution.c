#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>


void mysignal_handler(int signalno) {
    if (signalno == SIGURG) {
        exit(EXIT_SUCCESS);
    }
}

int main() {
    pid_t pid = fork();
    if (pid == 0) { // child
        printf("childpid = %d\n", getpid());
        setsid();
        printf("childpid = %d\n", getpid());

        signal(SIGURG, mysignal_handler);
        chdir("/");

        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        pause();
        exit(EXIT_SUCCESS);
    } else {        // parent
        printf("%d\n", pid);
    }
}
