#include "main.h"
int last_exit(int status)
{
        static int last = 0;
        int previous = 0;

        previous = last;
        last = status;
        return (previous);
}
/**
 * print_env - prints the environment variables
 * @env: array of environment variables
 */

void print_env(char **env)
{
	int i = 0, j = 0;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			write(STDOUT_FILENO, &env[i][j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * builtins - checks if a command is a builtin
 * @tokens: array of tokens
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 if builtin, 1 if not
 */

int builtins(char **tokens, char **argv, char **env)
{
	int status;
	(void)argv;

	status = last_exit(0);
	if (_strncmp(tokens[0], "exit", 4) == 0)
	{
		free(tokens);
		exit(status);
	}
	if (_strncmp(tokens[0], "env", 3) == 0)
	{
		print_env(env);
		return (0);
	}
	return (1);
}
/**
 * _getenv - gets an environment variable
 * @name: name of the environment variable
 * Return: pointer to the environment variable
 */

char *_getenv(char *name)
{
	char **env = NULL, *var = NULL, *value = NULL;
	int i = 0, j = 0, len = 0;

	env = environ;
	while (env[i] != NULL)
	{
		var = env[i];
		len = _strlen(name);
		for (j = 0; j < len; j++)
		{
			if (name[j] != var[j])
				break;
		}
		if (j == len && var[j] == '=')
		{
			value = var + len + 1;
			break;
		}
		i++;
	}
	return (value);
}

/**
 * tokenize - tokenizes a string
 * @line: string to tokenize
 * Return: pointer to an array of tokens
 */

char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, len = 0;

	len = _strlen(line);
	if (len == 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (len + 1));
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	token = strtok(line, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

