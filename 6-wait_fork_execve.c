#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - wait, fork and execve
 * Return: 0
 */

int main(void)
{
	pid_t process = 0;
	int children_count;
	char *command[] = {"/bin/ls", "-l", NULL};
	int status;
	
	for (children_count = 0; children_count < 5; children_count++)
	{
		process = fork();
		
		if (process < 0)
		{
			perror("fork failed");
			return (1);
		}

		if (process == 0)
		{
			
			printf("YES\n");
			execve("/bin/ls", command, NULL);
			break;
		}

		else
			wait(&status);
	}
	return (0);
}
