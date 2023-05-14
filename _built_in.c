#include "header.h"
/**
  * _built_in - check the right function to execute
  * @num: number of strings to compare
  * @func: name of function
  * Return: pointer to a void function or NULL
  */
void (*_built_in(int num, ...))(char *func)
{
int i, j;
char *a;
va_list ar;
built_t b_list[] = {
{"env", b_env},
{"cd", b_cd},
{"exit", b_exit},
{NULL, NULL}
};
va_start(ar, num);
for (j = 0; j < num; j++)
{
a = va_arg(ar, char *);
for (i = 0; b_list[i].b != NULL; i++)
{
if (strcmp(a, b_list[i].b) == 0)
{
va_end(ar);
return (b_list[i].p);
}
}
}
va_end(ar);
return (NULL);
}
/**
 * check_builtin - Checks for builtin functions that we need
 * @cmd: array of all the args passed to our shell.
 * @input: string that represent the input from the user
 * Return: 0 or-1.
 */
int check_builtin(char **cmd, char *input)
{
void (*create)(char *);
create = _built_in(1, cmd[0]);
if (create == NULL)
return (-1);
if (strcmp("exit", cmd[0]) == 0)
free_dptr(cmd);
create(input);
return (0);
}
