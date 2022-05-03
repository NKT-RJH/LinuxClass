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

int main()
{
	int fd1 = open("studentdb", O_RDONLY);
	STUDENT student;

	if (fd1 == -1)
	{
		printf("File Open Fail");
	}

	do
	{
		printf("Which school number do you want to search?");

		scanf("%d", &student.id);

		lseek(fd1, student.id * sizeof(student), SEEK_SET);

		if (read(fd1, student, sizeof(student)) > 0 && student.id != 0)
		{
			printf("ID : %d, NAME : %s, SCORE : %d\n", student.id, student.name, student.score);
		}

		printf("Keep Trying? (Y/N)");

		char c = '';
		scanf("%c", &c);

	} while (c == 'Y');
}