#include "header.h"
/**
 * tokenize - Tokenizes a string with the given delimiter
 * @str: string
 * @delimiter: given delimiter
 * Return: pointer
 */
char **tokenize(char *str, char *delimiter)
{
int i = 0;
char **tokens = malloc(sizeof(char *));
char *token = strtok(str, delimiter);
while (token != NULL)
{
tokens[i] = token;
i++;
tokens = realloc(tokens, sizeof(char *) * (i + 1));
token = strtok(NULL, delimiter);
}
tokens[i] = NULL;
return tokens;
}
