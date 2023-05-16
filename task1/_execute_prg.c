#include "../header.h"

/* fork() : create a new process.*/
/* perror() : This function displays the error message.*/
/* wait() :  Wait for completion of a process.*/
/*
 * The exit function allows you to end
 * the program by specifying a return value.
 *
 * exit(EXIT_FAILURE) : #define EXIT_FAILURE 1
 * indicate that the program is terminating incorrectly.
 *
 * exit(EXIT_SUCCESS) : #define EXIT_SUCCESS 0
 * indicate that the program is ending correctly.
 */
/*execve() : Execute an executable path with arguments*/

/*
 * execute_prg - executing a program.
 * Description: executing a program.
 * @cmd: executable file path.
 * @j: interger.
 * @av: double ponter.
 * Return: void function.
 */
void execute_prg(char **cmd, int *j, char **av)
{

pid_t pid;
pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}

else if (pid == 0)
{
_execute(*cmd, *av);
}

else
{
wait(j);
}

}
/**
 * _execute - execute the program.
 * @cmd: executable file path.
 * @av: double pointer.
 * Return: void function.
 */
void _execute(char *cmd, char *av)
{
int n;

char *envp[] = {NULL};
char *delim = " ";
char *args[] = {NULL};

_strtok(cmd, delim, args);

n = execve(cmd, args, envp);

if (n == -1)
{
perror((av + 0));
exit(EXIT_FAILURE);
}

exit(EXIT_SUCCESS);
}
