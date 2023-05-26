#include "header.h"
/**
 * f_cvint - converts a interger to a string
 * @num: integer
 * Return: a pointer to string.
 */
char *f_cvint(int num)
{
char *s;
int _negative, len, index;
if (num == 0)
{
s = (char *) malloc(2 * sizeof(char));
s[0] = '0';
s[1] = '\0';
return (s);
}
_negative = 0;
len = countDigits(num);
if (num < 0)
{
_negative = 1;
num = -num;
len++;
}
s = (char *) malloc((len + 1) * sizeof(char));
index = extractDigits(num, s);
if (_negative)
s[index++] = '-';
s[index] = '\0';
rev_str(s, index);
return (s);
}

/**
 * countDigits - counts the number of digits in a number
 * @num: integer
 * Return: number of digits
 */
int countDigits(int num)
{
int count = 0;
while (num > 0)
{
num = num / 10;
count++;
}
return (count);
}

/**
 * extractDigits - extracts the digits of a number
 * and stores them in a string
 * @num: integer
 * @s: string to store the digits
 * Return: index of the last digit in the string
 */
int extractDigits(int num, char *s)
{
int index = 0;
while (num > 0)
{
int digit = num % 10;
s[index++] = digit + '0';
num = num / 10;
}
return (index);
}
