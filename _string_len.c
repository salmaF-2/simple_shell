#include "header.h"
/**
 * f_strlen - count the lenght of a string.
 * @s: string
 * Return: lenght or -1
 */
int f_strlen(char *s)
{
size_t l;
if (!s)
return (-1);
l = 0;
while (s[l] != '\0')
l++;
return (l);
}
