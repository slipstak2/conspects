#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUF_SIZE 100

bool read_and_calc(int fd, int* ans) {
	char buf[BUF_SIZE + 1];
	int bytes = read(fd, buf, BUF_SIZE);
	if (bytes) {
		//printf("\nread fd=%d, bytes = %d:", fd, bytes);
		int i;
		for (i = 0; i < bytes; ++i) {
			//printf("%c", buf[i]);
			if (isdigit(buf[i])) {
				*ans += buf[i] - '0';
			}
		}
	}
	return bytes != 0;
}
int main() {
	int f1 = open("in1", O_NONBLOCK | O_RDONLY);
	int f2 = open("in2", O_NONBLOCK | O_RDONLY);

	//printf("open fd: %d %d\n", f1, f2);
	int ans = 0;
	fd_set read_set;
	bool isF1 = true, isF2 = true;
	while (isF1 || isF2) {
		FD_ZERO(&read_set);
		if (isF1) {
			FD_SET(f1, &read_set);
		}
		if (isF2) {
			FD_SET(f2, &read_set);
		}

		int result = select(f2 + 1, &read_set, NULL, NULL, NULL);

		if (result) {
			if (FD_ISSET(f1, &read_set)) {
				isF1 &= read_and_calc(f1, &ans);
			} 
			if (FD_ISSET(f2, &read_set)) {
				isF2 &= read_and_calc(f2, &ans);
			} 
		}
	}
	printf("%d\n", ans);
	return 0;
}
