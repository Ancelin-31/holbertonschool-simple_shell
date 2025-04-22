#include "shell.h"

/**
 * main - super simple command interpreter
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	char *args[4096];
	size_t len = 0;
	ssize_t read = 0;
	pid_t process = 0;
	int status;
	struct stat st;

	while (1)
	{
		memset(args, 0, sizeof(args));
		read = getline(&line, &len, stdin);
		if (read < 0)
			break;
		tokenize(line, args);

		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");
			
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
			execve(args[0], args, NULL);
			break;
		}

		else
			wait (&status);

	
	}
	free(line);
return (0);
}
