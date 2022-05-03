#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	DIR* dp;
	struct dirent* d;

	char directoryName[512];
	
	if (argc == 1)
	{
		strcpy(directoryName, ".");
	}
	else
	{
		strcpy(directoryName, argv[1]);
	}

	printf("directoryName = %s\n", directoryName);

	dp = opendir(directoryName);
	if (dp == NULL)
	{
		printf("dp is null");
		exit(0);
	}
	while ((d = readdir(dp)) != NULL)
	{
		printf("%s\n", d -> d_name);
	}

	return 0;
}