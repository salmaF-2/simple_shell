#include "header.h"
/**
 * f_digit - checks digits.
 * @s: what to check
 * Return: 1 is a digit or 0 if not
 */
int f_digit(char *s)
{
while (*s != '\0')
{
if (*s < '0' || *s > '9')
return (0);
s++;
}
return (1);
}
