#include <stdio.h>
#include <stdlib.h>
#include "../shell.h"

int main(void)
{
	char *input = read_line();

	printf("%s", input);

	return (0);
}
