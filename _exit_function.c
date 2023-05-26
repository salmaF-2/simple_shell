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
void exit_function(char **argv, char **arguments,
char *string, int index, int *errors, int *status)
{
if (!arguments[1])
{
handleNoArguments(errors, status, arguments, string);
return;
}
if (f_digit(arguments[1]) == 1)
{
handleNumericArgument(argv[0], arguments,
index, errors);
}
else
{
handleInvalidArgument(argv[0], arguments, index, errors);
}
_free_function(arguments);
}

/**
 * handleNoArguments - handles the case when there are no
 * arguments provided.
 *
 * @errors: exit errors.
 * @status: status of exit function.
 * @arguments: args
 * @string: strings
 * Return: void.
 */
void handleNoArguments(int *errors, int *status,
char **arguments, char *string)
{
if (*errors == 2 || *status == 2)
{
cleanupAndExit(2, arguments, string);
}
if (*status == 127)
{
cleanupAndExit(127, arguments, string);
}
else
{
cleanupAndExit(0, arguments, string);
}
}

/**
 * handleNumericArgument - handles the case when
 * the argument is a numeric value.
 *
 * @programName: name of the program.
 * @arguments: arguments.
 * @index: counter integer.
 * @errors: exit errors.
 *
 * Return: void.
 */
void handleNumericArgument(char *programName,
char **arguments, int index, int *errors)
{
unsigned int k = (unsigned int) f_atoi(arguments[1]);
if (k > (unsigned int) INT_MAX)
{
exit_function_errors(programName, arguments, index);
*errors = 2;
}
else
{
k %= 256;
_free_function(arguments);
exit(k);
}
}

/**
 * handleInvalidArgument - handles the case when the argument is invalid.
 *
 * @programName: name of the program.
 * @arguments: arguments.
 * @index: counter integer.
 * @errors: exit errors.
 *
 * Return: void.
 */
void handleInvalidArgument(char *programName,
char **arguments, int index, int *errors)
{
exit_function_errors(programName, arguments, index);
*errors = 2;
}
/**
 * cleanupAndExit - function to clean and exit
 * @exitStatus: exit status
 * @arguments: args
 * @string: strings
 */
void cleanupAndExit(int exitStatus, char **arguments,
char *string)
{
_free_function(arguments);
free(string);
exit(exitStatus);
}
