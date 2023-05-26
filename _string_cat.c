#include "header.h"
/**
 * f_strcat - function appends source string to the dest string
 * overwriting null byte at end of destination
 * @path: ptr appended by command
 * @cmd: pointer appended to path
 * Return: a pointer to destination
 */
char *f_strcat(char *path, char *cmd)
{
int a;
unsigned int i, j, plen, cmdlen, sizeb;
char *p;
(void) a;
plen = f_strlen(path);
cmdlen = f_strlen(cmd);
sizeb = plen + cmdlen + 2;
p = malloc(sizeof(char) * sizeb);
if (!p)
{
a = write(STDERR_FILENO, "Error: malloc failed\n", 22);
exit(98);
}
for (i = 0; i < plen; i++)
p[i] = path[i];
p[i] = '/';
for (i++, j = 0; j < cmdlen; j++)
p[i + j] = cmd[j];
p[i + j] = '\0';
return (p);
}
