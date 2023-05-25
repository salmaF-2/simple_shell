#include "../shell.h"

/**
 * main - entry point for the shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        prompt();
        line = read_line();
        args = split_line(line);
        
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return (0);
}
