#include "main.h"

/**
 * executeCommand - function execute the program
 * @args: arguments
 * Return: 0 or 1
 */
int executeCommand(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
execvp(args[0], args);
perror("Command execution error");
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork error");
return (1);
}
else
{
waitpid(pid, &status, 0);
}
return (0);
}

/**
 * freeMemory - free the memory
 * @args: arguments
 */
void freeMemory(char **args)
{
int i = 0;
while (args[i] != NULL)
{
free(args[i]);
i++;
}
free(args);
}

/**
 * splitInput - function that split input
 * @input: input from user
 * Return: arguments or NULL
 */
char **splitInput(char *input)
{
char **args = malloc(MAX_ARGS * sizeof(char *));
char *token;
int i = 0;
if (args == NULL)
return (NULL);
token = strtok(input, " ");
while (token != NULL)
{
args[i] = strdup(token);
if (args[i] == NULL)
{
freeMemory(args);
return (NULL);
}
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
return (args);
}
