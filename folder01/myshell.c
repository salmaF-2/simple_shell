#include "header.h"
/**
 * main - the entry point of my program
 * Return: returns 0
 */
int main(void)
{
pid_t pid;
char *c = NULL;
size_t size = 0;
ssize_t num_char;
while (1)
{
printf("#cisfun$ ");
num_char = getline(&c, &size, stdin);
if (num_char == -1)
{
printf("\n");
break;
}
if (num_char > 1 && c[num_char - 2] == '\n')
{
c[num_char - 2] = '\0';
}
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execute_command(c);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
free(c);
return (0);
}
