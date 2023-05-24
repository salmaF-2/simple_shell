#include "header.h"
/**
 * executeCommand - function execute the program
 * @args: arguments
 * Return: 0 or 1
 */
int executeCommand(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
execvp(args[0], args);
perror("Command execution error");
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork error");
return (1);
}
else
{
waitpid(pid, &status, 0);
}
return (0);
}
