#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>


/**
 * struct built_d - def the built-in functions.
 * @b: The name in  cmd
 * p: pointer to built-in function that we want
 */
typedef struct built_d
{
	char *b;
	void (*p)(char *);
} built_t;

extern char **environment;
void (*_built_in(int num, ...))(char *func);
int check_builtin(char **cmd, char *input);
void b_exit(char *input);
void b_cd(char *arguments);
void b_env(char *string);
void free_dptr(char **to_be_freed);
char **tokenize(char *str, char *delimiter);
#endif
