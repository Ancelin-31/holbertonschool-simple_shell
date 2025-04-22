#include "shell.h"

/**
 * main - super simple command interpreter
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	char *args[] = {NULL, NULL};
	size_t len = 0;
	pid_t process = 0;
	int status;
	struct stat st;

		while (1)
		{
			getline(&line, &len, stdin);
			line[strlen(line) - 1] = '\0';
			args[0] = line;
			
			if (stat(args[0], &st) != 0)
				fprintf(stderr, "hsh: 1: %s: not found\n", args[0]);
			process = fork();
			
			if (process < 0)
			{
				perror("fork failed");
				return (1);
			}

			if (process == 0)
			{
				execve(line, args, NULL);
				break;
			}

			else
				wait (&status);

			free(line);
		}
	return (0);
}
