#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char file_path[1024];
	sprintf(file_path, "/proc/%d/status", getpid());
	//printf("%s\n", file_path);

	const int ROW_SIZE = 1024;
	char row[ROW_SIZE + 1];
	FILE *fp = fopen(file_path, "r");
	while(!feof(fp)) {
		fgets(row, ROW_SIZE, fp);
		if (strstr(row, "PPid")) {
			//printf("%s", row);
			int parent_id;
			sscanf(row, "PPid: %d", &parent_id);
			printf("%d\n", parent_id);
		}
	}
	fclose(fp);
	return 0;
}
