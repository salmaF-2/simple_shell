#include "../header.h"

/* fget() : read the content of a string from a stream.*/
/* strcspn() : Returns the length of the largest string.*/
/* strtok() : A function for parsing strings into tokens.*/
/* fork() : create a new process.*/

/**
 * main - main function.
 * Description: Handle the PATH.
 *
 * Return: always 0.
 */
int main(void)
{
char cmds[MAXIMUM1];
char *strings[MAXIMUM2 + 2], *_token;
int i, s;
pid_t pid;

s = 0;

while (1)
{
printf(":) ");

if (fgets(cmds, sizeof(cmds), stdin) == NULL)
{
break;
}

cmds[strcspn(cmds, "\n")] = '\0';
_token = strtok(cmds, " \n");
i = 0;

while (_token != NULL && i < MAXIMUM2)
{
strings[i] = _token;
_token = strtok(NULL, " \n");
i++;
}

strings[i] = NULL;
pid = fork();

task3_test(pid, s, strings);
}

return (0);
}
