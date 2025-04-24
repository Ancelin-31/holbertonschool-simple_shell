#include "shell.h"

/**
 * tokenize - splits a string in an array of strings
 * @line: given string
 * Return: array of strings
 */

char **tokenize(char *line)
{
	char **args = malloc(1024 * sizeof(char));
	char *newLine = strdup(line);
	char *linetok = strtok(newLine, " \n");
	int i = 0, j = 0;

	if (args == NULL)
	{
		return (NULL);
	}

	if (newLine == NULL)
	{
		for (j = 0; args[j] != NULL; j++)
			free(args[j]);
		free(args);
		return (NULL);
	}
	while (linetok != NULL)
	{
		args[i] = strdup(linetok);
		linetok = strtok(NULL, " \n");
		i++;
	}
	args[i] = '\0';

	free(newLine);
	return (args);
}
