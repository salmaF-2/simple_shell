#include "header.h"
/**
 * main - the entry point of my program.
 * @ac: The number of parameters
 * @av: array of parameters
 * Return: 0
 */
int main(int ac, char **av)
{
char *line;
size_t size;
int command_counter;
command_counter = 0;
signal(SIGINT, SIG_IGN);
do {
command_counter++;
line = NULL;
size = 0;
parse_line(line, size, command_counter, av);
} while (1);
return (0);
}
