#include "header.h"
/**
 * f_strcmp - function compares two strings.
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if strings are the same or the diffrence
 */
int f_strcmp(char *s1, char *s2)
{
int i;
int a;
int r;
i = 0;
r = 0;
while (s1[i] != '\0')
i++;
for (a = 0; a <= i; a++)
{
if (s1[a] != s2[a])
{
r = s1[a] - s2[a];
break;
}
}
return (r);
}
