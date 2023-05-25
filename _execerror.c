#include "header.h"
/**
 * _execerror - function that Prints exec errors.
 * @av: The name of the prog
 * @count: Keeps track of count
 * @tmp_command: The filed cmd
 */

void _execerror(char *av, int count, char *tmp_command)
{
	_perror(av, count, tmp_command);
	write_string(": ", 1);
	perror("");
	exit(1);
}
