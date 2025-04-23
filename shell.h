#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *_getenv(char *string, char **env);
char *find_path(char *cmd, char **env);
void tokenize(char *line, char **args);

#endif
