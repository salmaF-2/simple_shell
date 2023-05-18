#include "header.h"
/**
 * _strtok - allows you to extract all the tokens from a string.
 * To control what is to be extracted, you must specify the set
 * of characters that can act as token separators.
 *
 * @string: the string to extract the list of tokens.
 * @separator : list of delimiters to be used for splitting the main string.
 * @arg: array ov strings
 *
 * Return: void
 */
void _strtok(char *string, char *separator, char **arg)
{
int i = 0;
char *str = strtok(string, separator);
while (str != NULL)
{
*(arg + i) = str;
str = strtok(NULL, separator);
i++;
}
*(arg + i) = NULL;
return;
}
