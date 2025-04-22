#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - waits for the user to enter a command, and prints it on the next line
 * Return: number of characters read, delimiters included but excluding NULL
 * (or -1 if failure in reading process)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t lineread;
       
	printf("$ ");

	lineread = getline(&line, &len, stdin);

	if (lineread != -1)
	{
		printf("%s", line);
		printf("%zd\n", lineread);
	}
	free(line);
	return (0);
}
