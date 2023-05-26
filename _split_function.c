#include "header.h"

/**
 * split_function - this function splits commands.
 *
 * @string: a pointer to the command line
 *
 * Return: an array of strings
 */
char **split_function(char *string)
{
char *token_, *token__, **arguments;
int index, k, count;
(void)k;
count = 0;
if (string[0] != ' ' && string[0] != '\t' && string[0] != '\n')
count++;
for (index = 0; string[index] != '\0'; index++)
{
if ((string[index] == ' ' || string[index] == '\t') &&
		string[index + 1] != ' ' && string[index + 1] != '\t' &&
		string[index + 1] != '\n')
count++;
}
if (count == 0)
return (NULL);
arguments = malloc((count + 1) * sizeof(char *));
if (arguments == NULL)
{
k = write(STDERR_FILENO, "Error: malloc failed\n", 22);
free(string);
exit(98);
}
token__ = strtok(string, "#");
token_ = strtok(token__, DELIM);
index = 0;
while (token_)
{
arguments[index] = f_strdup(token_);
if (arguments[index] == NULL)
{
k = write(STDERR_FILENO, "Error: malloc failed\n", 22);
_free_function(arguments);
exit(98);
}
token_ = strtok(NULL, DELIM);
index++;
}
arguments[count] = NULL;
return (arguments);
}
