#include "header.h"
/**
 * main - the entry point of my program
 * Return: returns 0 or -1
 */
int main(void)
{
pid_t pid;
char *c = NULL;
size_t size = 0;
ssize_t num_char_to_read;
do {
printf("#cisfun$ ");
num_char_to_read = getline(&c, &size, stdin);
if (num_char_to_read == -1)
{
return (-1);
}
c[num_char_to_read - 1] = '\0';
pid = fork();
if (pid == -1)
{
perror("fork");
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
} while (1);
free(c);
}
