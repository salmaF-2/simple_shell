#include "header.h"

/*Functions used :*/

/* feof :check if the current position is at the end of the file or not.*/

/* perror : allows to translate the error codes into an intelligible form*/

/* exit(EXIT_FAILURE) : indicate that your program is exiting in an anomalous way*/

/* fork() : create a child process*/

/* free : frees a dynamically allocated block of memory in the heap*/


/*
 * main - a UNIX command line interpreter.
 *
 * Return : always 0.
*/

int main(void)
{
pid_t pid;
char *token, **str;
int i;
size_t size = 0;
ssize_t num_char_to_read;
char *c = NULL;
do
{
printf("#cisfun$ ");
num_char_to_read = getline(&c, &size, stdin);
if (num_char_to_read == -1)
{
return (-1);
}
c[num_char_to_read - 1] = '\0';
i = 0;
pid = fork();
str = malloc(sizeof(char *));
token = strtok(c, " ");
while (token != NULL)
{
str[i++] = token;
str = realloc(str, sizeof(char *) * (i + 1));
token = strtok(NULL, " ");
}
str[i] = NULL;
if (pid == -1)
    perror("fork");
else if (pid == 0)
{
if (execvp(str[0], str) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
}
else
{
int j;
waitpid(pid, &j, 0);
}
free(str);
} while (1);
free(c);
}
