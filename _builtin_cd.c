#include "header.h"
/**
 * b_cd - function Changes the current directory of the process
 * @arguments: the argument passed after cd
 */
void b_cd(char *arguments)
{
char **args = tokenize(arguments, " ");
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
}
else if (chdir(args[1]) != 0)
{
perror("chdir");
}
free_tokens(args);
}
