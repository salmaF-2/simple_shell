#include "../header.h"

/* fork() : create a new process.*/
/* perror() : This function displays the error message.*/
/* waitpid() :  Wait for completion of a process.*/

/*
 * The exit function allows you to end
 * the program by specifying a return value.
 *
 * exit(EXIT_FAILURE) : #define EXIT_FAILURE 1
 * indicate that the program is terminating incorrectly.
 *
 * exit(EXIT_SUCCESS) : #define EXIT_SUCCESS 0
 * indicate that the program is ending correctly.
 * fprintf() : is used to write data to a file
 * using a stream object, not in the stdout.
 * execvp() : replaces the current process image with
 * a new process image specified by the file
 * WIFSIGNALED : Return True if the process returning
 * status was terminated by a signal.
 * WTERMSIG : Return the signal that terminated
 * the process that provided the status value.
 * WIFEXITED : Return True if the process returning
 * status exited via the exit() system call.
 * WEXITSTATUS : Return the process return code from status.
 */

/**
 * task3_test - execute the program.
 * @pid: child process.
 * @s: the status.
 * @strings: double pointer.
 *
 * Return: void function.
 */

void task3_test(pid_t pid, int s, char **strings)
{

if (pid == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(strings[0], strings) == -1)
{
fprintf(stderr, "Command not found: %s\n", strings[0]);
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
else
{
if (waitpid(pid, &s, 0) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}

if (WIFSIGNALED(s))
printf("%d\n", WTERMSIG(s));
else if (WIFEXITED(s))
printf("%d\n", WEXITSTATUS(s));
}
}
