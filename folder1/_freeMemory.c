#include "header.h"
/**
 * freeMemory - free the memory
 * @args: arguments
 */
void freeMemory(char **args)
{
int i = 0;
while (args[i] != NULL)
{
free(args[i]);
i++;
}
free(args);
}
