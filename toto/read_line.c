#include "shell.h"

/**
 * read_line - Splits a string into tokens
 *
 * Return: Pointer to an array of tokens or NULL if it fails
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t n = 0, command;

		command = getline(&lineptr, &n, stdin);

		if (!command) /*check getline input*/
			return (NULL);

		return (lineptr);
}
