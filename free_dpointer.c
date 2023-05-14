#include "header.h"
/**
 * free_dptr - Free double pointer
 * @to_be_freed: The address that need to be freed.
 */
void free_dptr(char **to_be_freed)
{
    char **tmp = to_be_freed;

    while (*tmp)
        free(*tmp++);
    free(to_be_freed);
}
