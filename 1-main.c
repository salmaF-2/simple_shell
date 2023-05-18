#include "header.h"

/* fflush() : flush the output buffer of the stream.*/

/*
 * stdout -> FILE * stdout;
 * the standard output stream of the application
 */

/* getline() : A function for reading input from the user.*/

/*
 * stdin -> FILE * stdin;
 * the standard input stream of the application.
 */

/**
 * main - main function
 * @ac: type of integer.
 * @av: array of strings.
 * Return: always 0 sucess.
 */
int main(int ac, char **av)
{
char *command = NULL;
size_t size = 0;
ssize_t num_char_to_read;
int k = 0;
(void)ac;
while (1)
{
printf("cisfun$ ");
fflush(stdout);
num_char_to_read = getline(&command, &size, stdin);
if (num_char_to_read == -1)
{
break;
}
command[num_char_to_read - 1] = '\0';
if (strcmp(command, "exit") == 0)
{
break;
}
execute_prg(&command, &k, av);
}
free(command);
return (0);
}
