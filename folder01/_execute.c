#include "header.h"
/**
 * execute_command - executes a command using execvp
 * @command: array of string
 */
void execute_command(char *command)
{
char *token, **args;
int i = 0;
args = malloc(sizeof(char *));
token = strtok(command, " ");
while (token != NULL)
{
args[i++] = token;
args = realloc(args, sizeof(char *) * (i + 1));
token = strtok(NULL, " ");
}
args[i] = NULL;
if (execvp(args[0], args) == -1)
{
perror("execvp");
}
free(args);
}
