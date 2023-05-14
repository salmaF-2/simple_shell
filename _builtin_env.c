#include "header.h"
/**
 * b_env - function to implement the environment
 * @string: string
 */
void b_env(char *string)
{
char **E = environment;
int i;
(void)string;
for (i = 0; E[i] != NULL; i++)
printf("%s\n", E[i]);
}
