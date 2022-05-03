#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	int fd = open("myfile", O_RDWR);
	if (fd == -2) {
		printf("File is nothing\n");
	}
	else {
		printf("Opening file successed!\n");
	}
	return 0;
}