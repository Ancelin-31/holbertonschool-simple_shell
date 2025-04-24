#include "shell.h"

/**
* _getenv - takes a string and environment variables as arguments
* Return: value of the given environment variable
*/

char * _getenv(char *string, char **env)
{
	size_t len;
	int i =0;
	len = strlen(string);
	
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], string, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
	}
	return (NULL);
}

/**
 * find_path - finds the full path to an input (if it exists)
 * @cmd: command
 * @env: environment
 * Return: pointer to path
 */

char *find_path(char *cmd, char **env)
{
	char *path, *copy, *dir, *full;
	size_t len; /* Si l'utilisateur donne un slash, teste directement */
	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
                { /* duplique cmd */
			len = strlen(cmd) + 1;
			full = malloc(len);
			if (full)
				strcpy(full, cmd);
			return (full);
		}
		return (NULL);
	}    /* Sinon, on récupère PATH */
	path = _getenv("PATH", env);
	if (!path)
		return (NULL);    /* copie PATH pour strtok */
	copy = malloc(strlen(path) + 1);
	if (!copy)
		return (NULL);
	strcpy(copy, path);    /* pour chaque répertoire de PATH */
	dir = strtok(copy, ":");
	while (dir)
        {/* construit "<dir>/<cmd>" */
		len  = strlen(dir) + 1 + strlen(cmd) + 1;
		full = malloc(len);
		if (!full)
			break;
		sprintf(full, "%s/%s", dir, cmd);        /* access() teste l'existence + droit X */
		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
        }
	free(copy);
	return (NULL);
}
