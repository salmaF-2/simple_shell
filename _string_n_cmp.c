#include "header.h"
/**
 * f_strncmp - function compares two strings.
 * @s1: the first string
 * @s2: the second string
 * @n: number of bytes
 * Return: 0 if are the same or returns the diffrence
 */
int f_strncmp(char *s1, char *s2, size_t n)
{
size_t i;
for (i = 0; i < n; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
if (s1[i] == '\0')
return (0);
}
return (0);
}
