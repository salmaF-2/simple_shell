#include "header.h"
/**
 * f_atoi - convert a string to an integer
 * @s: string.
 * Return: an integer
 */
int f_atoi(char *s)
{
int i;
int sg;
int n;
int f;
unsigned int num;
sg = 1;
num = 0;
for (i = 0; *(s + i) != '\0'; i++)
{
if (*(s + i) == '-')
sg *= -1;
else if (*(s + i) >= '0' && *(s + i) <= '9')
{
f = 1;
n = i + 1;
while (*(s + n) >= '0' && *(s + n) <= '9')
{
f *= 10;
n++;
}
num += (*(s + i) - '0') * f;
if (!(*(s + i + 1) >= '0' && *(s + i + 1) <= '9'))
break;
}
else
continue;
}
return (num *sg);
}
