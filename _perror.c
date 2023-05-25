#include "header.h"
/**
 * _perror - Prints a message error
 * @count: counter
 * @av: The name of the prog
 * @command: cmd not being found.
 */
void error_printing(char *av, int count, char *command)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}
