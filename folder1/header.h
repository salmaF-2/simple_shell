#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
void displayPrompt(void);
char **splitInput(char *input);
int executeCommand(char **args);
void freeMemory(char **args);

#endif
