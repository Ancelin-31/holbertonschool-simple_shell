#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - super simple command interpreter
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t command;

	if (command != -1)
	{
		while (1)
		{
			command = getline(&line, &len, stdin);
			line[command] = '\0';
			printf("%s", line);
			printf("%i\n", command);
		}
	}
	free(line);
	return (0);
}
