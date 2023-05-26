#include "header.h"
/**
 * f_cvint - converts a interger to a string
 * @num: integer
 * Return: a pointer to string.
 */
char *f_cvint(int num)
{
char *s;
int _negative;
int len;
int digit;
int index;
int temp;
if (num == 0)
{
s = (char *) malloc(2 * sizeof(char));
s[0] = '0';
s[1] = '\0';
return (s);
}
_negative = 0;
len = 0;
if (num < 0)
{
_negative = 1;
num = -num;
}
temp = num;
while (temp > 0)
{
temp = temp / 10;
len++;
}
if (_negative)
{
len++;
}
s = (char *) malloc((len + 1) * sizeof(char));
index = 0;
while (num > 0)
{
digit = num % 10;
s[index++] = digit + '0';
num = num / 10;
}
if (_negative)
{
s[index++] = '-';
}
s[index] = '\0';
rev_str(s, index);
return (s);
}
