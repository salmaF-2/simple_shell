#include "shell.h"

/**
 * env_command - Prints the environment variables to the standard output.
 *
 * Return: Always returns 0.
 */
int env_command(void)
{
	int index = 0;
	char **curr_env = environ;

	while (curr_env[index] != NULL)
	{
	write(1, curr_env[index], strlen(curr_env[index]));
	write(1, "\n", 1);
	index++;
	};

	return (0);
}
