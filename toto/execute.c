#include "shell.h"

/**
 * execute - Executes a command with the given arguments.
 *
 * @args: An array of command arguments.
 * Return: 0 if the command is "exit",
 *	1 if executed successfully, -1 if an error occurred.
 */
int execute(char **args)
{
	pid_t pid;
	int status;
	char *command_path;

	if (!args[0])
	return (1);

	if (strcmp(args[0], "exit") == 0)
	return (0);

	pid = fork();
	if (pid == 0)
	{
		if (check_builtin(args))
			exit(EXIT_SUCCESS);
		else
		{
			command_path = get_path(args);
			if (command_path != NULL)
                args[0] = strdup(command_path);
		}
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
