#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int cnt1 = 0;
int cnt2 = 0;
void mysignal_handler(int signalno) {
	if (signalno == SIGUSR1) {
		//printf("SIGUSR1\n");
		cnt1++;
	} else if(signalno == SIGUSR2) {
		//printf("SIGUSR2\n");
		cnt2++;
	} else if (signalno == SIGTERM) {
		printf("%d %d\n", cnt1, cnt2);
		exit(EXIT_SUCCESS);
	}
}

int main() {
	signal(SIGUSR1, mysignal_handler);
	signal(SIGUSR2, mysignal_handler);
	signal(SIGTERM, mysignal_handler);
	while (true) {
		pause();
	}
	return 0;
}
