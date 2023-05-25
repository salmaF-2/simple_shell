#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10
#define MAX_LINE_LEN 1024

extern char **environ;

/**
 * struct Command - Structure representing a command in the shell.
 * @command: The command string.
 * @function: The function pointer.
 * Description: This structure is used to map a command
 */
typedef struct Command
{
	const char *command;
	int (*function)(void);
} Command;

/* Function Prototypes */
void prompt(void);
char *read_line(void);
char **split_line(char *line);
int env_command(void);
char *get_path(char **args);
int execute(char **args);
int check_builtin(char **command);

#endif /* SHELL_H */
