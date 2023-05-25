#include "shell.h"

/**
 * get_path - Retrieves the full path of a command
 * from the system's PATH environment variable.
 *
 * @args: An array of command arguments,
 *  where args[0] represents the command name.
 * Return: The full path of the command if found in the PATH, NULL otherwise.
 */
char *get_path(char **args)
{
	char *path_env;
	char *path;
	char *path_token;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path = strdup(path_env);
	if (path == NULL)
		return (NULL);

	path_token = strtok(path, ":");
	while (path_token != NULL)
	{
		char *command_path = malloc(strlen(path_token) + strlen(args[0]) + 2);

		if (command_path == NULL)
		{
			perror("malloc");
			free(path);
			return (NULL);
		}

	sprintf(command_path, "%s/%s", path_token, args[0]);

	if (access(command_path, X_OK) == 0)
	{
		free(path);
		return (command_path);
	}

	free(command_path);
	path_token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
