#include "header.h"
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
