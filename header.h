#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <stddef.h>
#include <fcntl.h>
#include <limits.h>

#define DELIM " \t\r\n\v\a"

extern char **environ;

/* ----------------exit with arguments---------------------*/
void exit_function(char **argv, char **arguments, char *string,
int index, int *errors, int *status);
/* --------   -----function free----------------------------*/
void _free_function(char **arguments);
/* -----------print environment variables-------------------*/
void environment_arguments(char **arguments);
char *getenv_function(char *variable_env);
/* -------------------split command line--------------------*/
char **split_function(char *string);
/* --------------------check for path-----------------------*/
int find_path(char *string);
/* -------------------------prompt--------------------------*/
void signal_request(int signal_v);
/* -------------------------errors--------------------------*/
void error_function(char *arguments, char *command_line,
int number, int z, int *status);
void exit_function_errors(char *arguments_vect, char **arguments,
int index);

/*other function used*/
char *f_strcat(char *path, char *cmd);
int f_strcmp(char *s1, char *s2);
char *f_strdup(const char *s);
int f_strlen(char *s);
int f_strncmp(char *s1, char *s2, size_t n);
void rev_str(char *s, int len);
char *f_cvint(int num);
int f_atoi(char *s);
int f_digit(char *s)
#endif
