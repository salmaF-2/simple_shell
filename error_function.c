#include "header.h"

/**
 * error_function - this function checks for errors.
 *
 * @arguments: argument.
 * @command_line: the command line.
 * @number: integer counter.
 * @z: check for the path.
 * @status: status of exit function.
 *
 * Return: void.
 */

void error_function(char *arguments, char *command_line,
		int number, int z, int *status)
{
int k;
char *ptr, *token_;

ptr = f_cvint(number);
(void)k;
if (z == 1)
{
token_ = strtok(command_line, "/");
while (token_)
{
command_line = token_;
token_ = strtok(NULL, "/");
}
}
k = write(STDERR_FILENO, arguments, f_strlen(arguments));
k = write(STDERR_FILENO, ": ", 2);
k = write(STDERR_FILENO, ptr, f_strlen(ptr));
k = write(STDERR_FILENO, ": ", 2);
k = write(STDERR_FILENO, command_line, f_strlen(command_line));
k = write(STDERR_FILENO, ": ", 2);
if (f_strcmp(strerror(errno), "Permission refused") == 0)
{
perror("");
*status = 126;
}
else
{
k = write(STDERR_FILENO, "not found\n", 10);
*status = 127;
}
free(ptr);
}
