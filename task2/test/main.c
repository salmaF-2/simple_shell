#include "../header.h"

int main(void)
{
    char *cmd_line = NULL;
    size_t size = 0;

    prompt();
    getline(&cmd_line, &size, stdin);

    printf("this is your input %s\n", cmd_line);

    return (0);
}