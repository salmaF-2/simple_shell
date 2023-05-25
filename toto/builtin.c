#include "shell.h"

/**
 * exit_command - exit from the shell
 *
 * Return: - 0
 */
int exit_command(void)
{
	printf("Exiting program...\n");
	return (0);
}

/**
 * check_builtin - Checks if a given command is a built-in
 * command and executes it if found.
 *
 * @command: An array of command arguments, where command[0]
 * represents the command name.
 * Return: The return value of the executed built-in
 * command if found, 0 otherwise.
 */
int check_builtin(char **command)
{
	Command commands[] = {
	{ "exit", exit_command },
	{ "env", env_command },
};

	int num_commands = sizeof(commands) / sizeof(commands[0]);
	int i;

	for (i = 0; i < num_commands; i++)
	{
	if (strcmp(*command, commands[i].command) == 0)
		{
		return (commands[i].function());
		}
	}
	return (0);
}
