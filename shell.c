#include "shell.h"

/**
 * main - simple shell interpreter
 * @argc: argument count
 * @argv: argument values
 * @env: environment variables
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **args = NULL;
	size_t linecap = 0;
	ssize_t lineread;
	int i;
	(void)argc;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		
		lineread = getline(&line, &linecap, stdin);
		
		if (lineread < 0)
			break;
		args = tokenize(line);
		
		if (args && args[0])
			handle_command(args, argv, env);
		
		for (i = 0; args && args[i]; i++)
			free(args[i]);
		free(args);
	}
	free(line);
	return (0);
}
