#include <stdio.h>
#include <stdlib.h>
#include "../shell.h"

int main(void) {
    char line[MAX_LINE_LEN] = "ls -la";
    char **args;
    int i;

    line[strcspn(line, "\n")] = '\0';

    args = split_line(line);

    for (i = 0; args[i] != NULL; i++) {
        printf("args[%d] = \"%s\"\n", i, args[i]);
    }

    free(args);

    return 0;
}
