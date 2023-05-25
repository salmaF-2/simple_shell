#include "shell.h"

/**
 * prompt - Displays a prompt on the command line.
 *
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
}
