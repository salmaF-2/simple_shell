#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/types.h>
#include <stddef.h>


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

/*--------function used for task1--------*/
void execute_prg(char **cmd, int *j, char **av);
void _execute(char *cmd, char *av);
void _strtok(char *string, char *separator, char **arg);
/*-------------------------------------------------------*/


extern char **environment;
/*-----------------*/
void (*_built_in(int num, ...))(char *func);
int check_builtin(char **cmd, char *input);
void b_exit(char *input);
void b_cd(char *arguments);
void b_env(char *string);
void free_dptr(char **to_be_freed);
char **tokenize(char *str, char *delimiter);
#endif
