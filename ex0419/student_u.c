#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct
{
	char name[24];
	int id;
	int score;
} STUDENT;

void stdempty()
{
	while (getchar() == '\n');
}

int main()
{
	int fd;
	fd = open("studentdb", O_RDWR);

	if (fd == -1)
	{
		printf("file open fail");
	}

	/*fd1 = open("studentdb", O_RDONLY);
	printf("fd = %d", fd);
	printf("fd1 = %d", fd1);*/
	char c;
	STUDENT student;

	do
	{
		printf("Input Student ID : ");
		scanf("%d", &student.id);
		getchar();
		if (student.id > 0)
		{
			lseek(fd, sizeof(student) * student.id, SEEK_SET);
			read(fd, &student, sizeof(student));

			printf("ID = %d, NAME = %s, SCORE = %d\n", student.id, student.name, student.score);

			printf("Input Score To Change : ");
			scanf("%d", &student.score);
			stdempty();
			if (student.score != 0)
			{
				lseek(fd, -sizeof(student), SEEK_CUR);
				write(fd, &student, sizeof(student));
				
			}
		}

		printf("Try Again? Y/N : ");
		scanf("%c", &c);
		getchar();
	} while (c == 'Y' || c == 'y');

	close(fd);

	return 0;
}