#include "shell.h"/**
* _getenv - takes a string and environment variables as arguments
* Return: value of the given environment variable
	*/
char * _getenv(char *string, char **env)
{
	size_t len;
	int i =0;    len = strlen(string);
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], string, len) == 0 && env[i][len] == '=')
			return env[i] + len + 1;
	}
	return NULL;
}
