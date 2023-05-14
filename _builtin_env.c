#include "header.h"
/**
 * b_env - function to implement the environment
 * @string: string
 */
void b_env(char *string)
{
(void)string;
char **E;
**E = environment; /*copy of global environment array*/
while (*E)
{
printf("%s\n", *E);
E++;
}
}
