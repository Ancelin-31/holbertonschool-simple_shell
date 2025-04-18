#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - allows a process to execute another program
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;

	getline(&line, &len, stdin);

	printf("Before execve\n");
	
	if (execve(len, line, NULL) == -1)
		perror("Error: ");

	printf("After execve\n");
	return (0);
}
