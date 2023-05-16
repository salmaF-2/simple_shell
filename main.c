#include "header.h"
/**
 * main - entry point
 * Return: 0
 */
char **environment;
int main(void)
{
int i, num_vars = 3;
environment = malloc(sizeof(char *) * (num_vars + 1));
environment[0] = strdup("VAR1=value1");
environment[1] = strdup("VAR2=value2");
environment[2] = strdup("VAR3=value3");
environment[num_vars] = NULL;
b_env("some string");
for (i = 0; i < num_vars; i++)
{
free(environment[i]);
}
free(environment);
return (0);
}
