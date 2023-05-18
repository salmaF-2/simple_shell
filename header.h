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

/*--------function used for task1--------*/
void execute_prg(char **cmd, int *j, char **av);
void _execute(char *cmd, char *av);
void _strtok(char *string, char *separator, char **arg);
/*-------------------------------------------------------*/
void task3_test(pid_t pid, int s, char **strings);

extern char **environ;
/*-----------------*/
void b_exit(void);
#endif
