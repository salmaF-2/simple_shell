#include "header.h"

/**
 * _cd - Changes working directory.$
 *
 * @cmd: A string representing the input from the user.
 * Return: void.
 */
void _cd(char *cmd)
{
int j;
int count;
char **arrayy;
const char *delim = "\n\t ";
count = 0;
arrayy = func_token(cmd, delim, count);
if (arrayy[0] == NULL)
{
_sfree(2, arrayy, cmd);
return;
}
if (arrayy[1] == NULL)
{
j = _path("HOME");
chdir((environ[j]) + 5);
}
else if (str_strcmp(arrayy[1], "-") == 0)
write_string(arrayy[1], 0);
else
chdir(arrayy[1]);
_dfree(arrayy);
}

/**
 * _env - Prints environmental variables.
 *
 * @cmd: the input from the user.
 * Return: void.
 */

void _env(__attribute__((unused))char *cmd)
{
int i, j;
for (i = 0; environ[i] != NULL; i++)
{
for (j = 0; environ[i][j] != '\0'; j++)
write(STDOUT_FILENO, &environ[i][j], 1);
write(STDOUT_FILENO, "\n", 1);
}
}

/**
 * _exit - Exiting the shell.
 *
 * @cmd: the input from the user.
 * Return: void.
 */
void _exit(char *cmd)
{
free(cmd);
write_string("\n", 1);
exit(1);
}

/**
 * find_buildin_s - Finds buildins function.
 *
 * @str: The name of the function.
 *
 * Return: void.
 */
void (*find_buildin_s(char *str))(char *str)
{
int i;
build_struct buildins[] = {
{"exit", _exit},
{"env", _env},
{"cd", _cd},
{NULL, NULL}
};
for (i = 0; buildins[i].built != NULL; i++)
{
if (str_strcmp(str, buildins[i].built) == 0)
{
return (buildins[i].f);
}
}
return (NULL);
}

/**
 * _buildins2 - Checks for buildins.
 * @line: arguments.
 * @cmd: the input from the user.
 *
 * Return: return 0 or -1.
 */
int _buildins2(char **line, char *cmd)
{
void (*build)(char *);
build = find_buildin_s(line[0]);
if (build == NULL)
return (-1);
if (str_strcmp("exit", line[0]) == 0)
double_free(line);
build(cmd);
return (0);
}
