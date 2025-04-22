#include "shell.h"

/**
 * tokenize - splits a string and returns an array of each word of thhe string
 * Return: array of each word of the string
 */

int tokenize(void)
{
	char *linetok;
	char *line = NULL;
	size_t len = 0;

	getline(&line, &len, stdin);
	linetok = strtok(line, " ");

	while (linetok != NULL)
		linetok = strtok(NULL, " ");

	return (0);
}
