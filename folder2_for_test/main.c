#include "main.h"

/**
 * execute - executes a command
 * @tokens: array of tokens
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int execute(char **tokens, char **argv, char **env)
{
	char *command = NULL;
	pid_t child_pid = 0;
	int status = 0;

	if (builtins(tokens, argv, env) == 0)
		return (0);
	command = get_path(tokens[0]);
	if (command == NULL)
		return (1);
	if (!access(command, X_OK))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(command, tokens, env) == -1)
			{
				perror(argv[0]);
				free(command);
				exit(1);
			}
		}
		else
			wait(&status);
	}
	return (status);
}
/**
 * get_path - gets the path of a command
 * @cmd: command to get the path of
 * Return: path of the command
 */

char *get_path(char *cmd)
{
	char *path = NULL, *path_copy = NULL, *token = NULL, *cmd_path = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);
	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	path = _getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = make_path(token, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			return (cmd_path);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 * make_path - creates a path to a command
 * @path: path to the command
 * @cmd: command to create the path to
 * Return: pointer to the path
 */

char *make_path(char *path, char *cmd)
{
	char *cmd_path = NULL;

	cmd_path = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (cmd_path == NULL)
		return (NULL);
	_strcpy(cmd_path, path);
	_strcat(cmd_path, "/");
	_strcat(cmd_path, cmd);
	return (cmd_path);
}

/**
 * main - starting point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **tokens = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int status = 0;

	(void)argc;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		tokens = tokenize(line);
		if (tokens == NULL)
			continue;
		status = execute(tokens, argv, env);
		free(tokens);
	}
	free(line);
	return (status);
}
