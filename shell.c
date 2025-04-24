#include "shell.h"

/**
 * main - interprets commands
 * @argc: number of arguments in the command
 * @argv: text composing the command
 * Return: 0 if success
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **args = NULL, *cmd_path = NULL;
	size_t linecap;
	ssize_t lineread;
	pid_t pid;
	int status;
	(void)argc;  /* on n’utilise pas argc directement */
	linecap = 0;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($)");
		}
		lineread = getline(&line, &linecap, stdin);
		if (lineread < 0)
		{
			break;
		}
		args = tokenize(line);
		
		if (args[0] == NULL)
		{
			free(line);
			continue;
		}
		cmd_path = find_path(args[0], env);
		
		if (cmd_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			continue;
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			free(cmd_path);
			continue;
		}
		if (pid == 0)
		{
			execve(cmd_path, args, env);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		waitpid(pid, &status, 0);
		free(cmd_path);
	}
	free(args);
	free(line);
	return 0;
}
