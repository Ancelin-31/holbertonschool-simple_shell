#include "shell.h"
#include <errno.h>
#include <unistd.h>


char *find_path(char *cmd, char **env)
{
	char *path, *copy, *dir, *full;
	size_t len;    /* Si l'utilisateur donne un slash, teste directement */
	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
		{
			/* duplique cmd */
			len = strlen(cmd) + 1;
			full = malloc(len);
			if (full)
				strcpy(full, cmd);
			return full;
		}
		return NULL;
	}    /* Sinon, on récupère PATH */
	path = _getenv("PATH", env);
	if (!path)
		return NULL;    /* copie PATH pour strtok */
	copy = malloc(strlen(path) + 1);
	if (!copy)
		return NULL;
	strcpy(copy, path);    /* pour chaque répertoire de PATH */
	dir = strtok(copy, ":");
	while (dir)
	{
		/* construit "<dir>/<cmd>" */
		len  = strlen(dir) + 1 + strlen(cmd) + 1;
		full = malloc(len);
		if (!full)
			break;
		sprintf(full, "%s/%s", dir, cmd);        /* access() teste l'existence + droit X */
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return full;
		}
		free(full);
		dir = strtok(NULL, ":");
	}    free(copy);
	return NULL;
}int main(int argc, char **argv, char **env)
{
	char *line;
	char *args[4096];
	size_t linecap;
	ssize_t nread;
	pid_t pid;
	int status;
	char *cmd_path;    (void)argc;  /* on n’utilise pas argc directement */    line = NULL;
	linecap = 0;    while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");        nread = getline(&line, &linecap, stdin);
		if (nread < 0)
			break;        tokenize(line, args);
		if (args[0] == NULL)
			continue;        cmd_path = find_path(args[0], env);
		if (cmd_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			continue;
		}        pid = fork();
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
	}    free(line);
	return 0;
}
