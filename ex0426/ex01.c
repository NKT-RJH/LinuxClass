#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);

	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);

	struct stat buf;

	lstat(argv[1], &buf);
	printf("stat %o %x\n", buf.st_mode, buf.st_mode);

	if (S_ISREG(buf.st_mode))
		printf("%s \n", "Normal File\n");
	if (S_ISDIR(buf.st_mode))
		printf("%s \n", "Directory\n");

	return 0;
}