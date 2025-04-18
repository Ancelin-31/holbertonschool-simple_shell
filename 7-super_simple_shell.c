#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple command interpreter
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t command;

	char *command = getline(&line, &len, stdin);

	if (command != -1)
	{
		printf("%s", line);
		printf("%zd\n", command);
	}

	free(line);
	return (0);
}
