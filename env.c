#include "shell.h"

/**
 * _getenv - takes a string and environment variables as arguments
 * Return: value of the given environment variable
 */

char * _getenv(char *string, char **envp)
{
	int i = 0, n = 0;
	n = strlen(string);
	char *variable;

	while (strcmp(string, envp[i], n) != 0)
		i++;

	if (env[i] != NULL)
	{
		variable = strtok(env[i], "=\n");
		variable = strtok(NULL, "=\n");
		return(variable);
	}

	else
		return(NULL);
}

/**
 * create_array - 
