#include "header.h"

/**
* signal_request - a function called for a signal.
*
* @signal_v: counter.
*
* Return:void.
*/
void signal_request(int signal_v)
{
(void) signal_v;
write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
