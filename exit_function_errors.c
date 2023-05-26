#include "header.h"

/**
 * exit_function_errors - =checks for exit errors.
 *
 * @arguments_vect: argument.
 * @arguments: arguments for command line.
 * @index: integer.
 *
 * Return: void.
 */
void exit_function_errors(char *arguments_vect, char **arguments, int index)
{
int k;
char *ptr;

ptr = f_cvint(index);
(void)k;
k = write(STDERR_FILENO, arguments_vect, f_strlen(arguments_vect));
k = write(STDERR_FILENO, ": ", 2);
k = write(STDERR_FILENO, ptr, f_strlen(ptr));
k = write(STDERR_FILENO, ": ", 2);
k = write(STDERR_FILENO, arguments[0], f_strlen(arguments[0]));
k = write(STDERR_FILENO, ": Illegal number: ", 18);
k = write(STDERR_FILENO, arguments[1], f_strlen(arguments[1]));
k = write(STDERR_FILENO, "\n", 2);
free(ptr);
}
