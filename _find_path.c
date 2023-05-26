#include "header.h"

/**
 * find_path - function that checks the path.
 *
 * @string: a stringing variable.
 *
 * Return: 0 in success or 1 == failed.
 */
int find_path(char *string)
{
int index;

for (index = 0; string[index] != '\0'; index++)
{
if (string[index] == '/')
{
return (0);
}
}

return (1);
}
