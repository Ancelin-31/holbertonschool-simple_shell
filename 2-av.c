#include <stdio.h>
#include <unistd.h>

/**
 * main - prints all arguments without using ac
 * @ac: number of arguments
 * @av: arguments, array of strings
 * Return: 0
 */

int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
