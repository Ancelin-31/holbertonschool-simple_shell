#include "shell.h"

/**
 * handle_command - handles command execution
 * @args: tokenized input
 * @argv: program name for error message
 * @env: environment variables
 */

void handle_command(char **args, char **argv, char **env)
{
	pid_t pid;
	char *cmd_path = find_path(args[0], env);
	int status;

	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		return;
	}	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		free(cmd_path);
		return;
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
