#include "header.h"

/**
 * environment_arguments - a function that prints environment variables.
 *
 * @arguments: Double pointer.
 *
 * Return: void.
 */
void environment_arguments(char **arguments)
{
char **environment, *string;
ssize_t n;

(void)n;
if (arguments[1] != NULL)
{
string = "environment: ‘";
n = write(STDERR_FILENO, string, f_strlen(string));
n = write(STDERR_FILENO, arguments[1], f_strlen(arguments[1]));
string = "’: no such file or directory\n";
n = write(STDERR_FILENO, string, f_strlen(string));
}
else
{
environment = environ;
while (*environment)
{
n = write(1, *environment, f_strlen(*environment));
n = write(1, "\n", 2);
environment++;
}
}
}
