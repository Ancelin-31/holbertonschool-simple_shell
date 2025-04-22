#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string
 * Return: array of each word of the string
 */

int main(void)
{
	char *linetok;
	char *line = NULL;
	size_t len = 0;

	getline(&line, &len, stdin);
	linetok = strtok(line, " ");

	while (linetok != NULL)
	{
		printf("%s", linetok);
		linetok = strtok(NULL, " ");
	}
	return (0);
}
