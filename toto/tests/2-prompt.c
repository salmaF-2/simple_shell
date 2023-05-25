#include "../shell.h"

int main(void)
{
	char *full_command = NULL;
	size_t n = 0;

	prompt();
	getline(&full_command, &n, stdin);

	printf("You typed %s\n", full_command);

	return (0);
}
