#include "header.h"
/**
 * _lstring - the lenght of a string.
 * @str: String
 * Return: length of a string otherwise 0.
 */
int _lstring(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
