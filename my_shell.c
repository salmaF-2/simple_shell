#include "main.h"

/**
 * main - entry point of the program.
 * Return: 0
 */
int main(void)
{
char input[MAX_INPUT_LENGTH];
char **args;
int status;
int firstIteration = 1;
while (1)
{
if (!firstIteration)
displayPrompt();
firstIteration = 0;
if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}
input[strcspn(input, "\n")] = '\0';
args = splitInput(input);
if (args == NULL)
{
printf("Memory allocation error\n");
continue;
}
status = executeCommand(args);
freeMemory(args);
if (status == -1)
break;
}
return (0);
}

/**
 * displayPrompt - function that display shell prompt
 */
void displayPrompt(void)
{
printf("\n#cisfun$ ");
}
