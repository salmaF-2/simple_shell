#include "header.h"

/**
 * exit_function - this function checks for exit status.
 *
 * @argv: argument.
 * @arguments: arguments.
 * @string: string.
 * @index: counter integer.
 * @errors: exit errors.
 * @status: status of exit function.
 *
 * Return: void.
 */
void exit_function(char **argv, char **arguments, char *string, int index,
		int *errors, int *status)
{
unsigned int k;
if (!arguments[1])
{
if (*errors == 2 || *status == 2)
{
_free_function(arguments);
free(string);
exit(2);
}
if (*status == 127)
{
_free_function(arguments);
free(string);
exit(127);
}
else
{
_free_function(arguments);
free(string);
exit(0);
}
}
if (f_digit(arguments[1]) == 1)
{
k = (unsigned int)f_atoi(arguments[1]);
if (k > (unsigned int)INT_MAX)
{
exit_function_errors(argv[0], arguments, index);
*errors = 2;
}
else
{
k %= 256;
_free_function(arguments);
exit(k);
}
}
else
{
exit_error(argv[0], arguments, index);
*errors = 2;
}
_free_function(arguments);
}
