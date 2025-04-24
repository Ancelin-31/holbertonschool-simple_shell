#include "shell.h"

void tokenize(char *line, char **args)
{
	char *linetok;
	int i = 0;    i = 0;
	linetok = strtok(line, " \n");
	while (linetok)
	{
		args[i] = linetok;
		i++;
		linetok = strtok(NULL, " \n");
	}
	args[i] = NULL;
}
