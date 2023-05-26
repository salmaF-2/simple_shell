#include "header.h"
/**
 * f_strdup - duplicates a string.
 * @s: string
 * Return: duplicated string or NULL
 */
char *f_strdup(const char *s)
{
size_t i;
size_t l = strlen(s) + 1;
char *dup = malloc(l);
if (dup == NULL)
{
return (NULL);
}
for (i = 0; i < l; i++)
{
dup[i] = s[i];
}
return (dup);
}
