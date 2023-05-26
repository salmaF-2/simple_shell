#include "header.h"
/**
 * rev_str - reverse a string
 * @s: string
 * @len: length of the string
 * Return: void.
 */

void rev_str(char *s, int len)
{
char temp;
int e;
int f = 0;
e = len - 1;
while (f < e)
{
temp = s[f];
s[f] = s[e];
s[e] = temp;
f++;
e--;
}
}
