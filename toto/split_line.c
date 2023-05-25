#include "shell.h"

/**
 * split_line - Splits a string into tokens
 * @line: Pointer to the input string
 *
 * Return: Pointer to an array of tokens or NULL if it fails
 */
char **split_line(char *line)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *lineptr_copy = NULL;
	char *token;
	int i = 0;
	int len;

	if (!args)
	{
		exit(EXIT_FAILURE);
	}

	lineptr_copy = malloc(sizeof(char) * strlen(line));
	if (lineptr_copy == NULL)
		exit(EXIT_FAILURE);

	strcpy(lineptr_copy, line);

	token = strtok(lineptr_copy, " ");
	while (token != NULL)
	{
		args[i] = malloc(strlen(token) + 1);
		if (!args[i])
			exit(EXIT_FAILURE);
	strcpy(args[i], token);

	len = strlen(args[i]);
	if (len > 0 && args[i][len - 1] == '\n')
		args[i][len - 1] = '\0';
	token = strtok(NULL, " ");
	i++;
	}
	args[i] = NULL;

	free(lineptr_copy);
	return (args);
}
