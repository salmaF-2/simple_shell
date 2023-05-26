#include "header.h"

/**
 * _free_function - Frees the memory.
 *
 * @arguments: string.
 *
 * Return: void.
 */
void _free_function(char **arguments)
{
char **pointer = arguments;

while (*pointer)
{
free(*pointer);
pointer++;
}
free(arguments);
}
