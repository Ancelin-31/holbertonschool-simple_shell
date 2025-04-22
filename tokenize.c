#include "shell.h"

/**
 * tokenize - splits a string and returns an array of each word of thhe string
 * Return: array of each word of the string
 */

void tokenize(char *line, char **args)
{
	char *linetok;
	int i = 0;

	linetok = strtok(line, " \n");

	while (linetok != NULL)
	{	
		args[i] = linetok;
		linetok = strtok(NULL, " \n");
		i++;
	}
}
