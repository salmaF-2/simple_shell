#include "header.h"
/**
 * _dfree - Free double pointer
 * @to_be_freed: elements that need to be freed.
 */
void _dfree(char **to_be_freed)
{
	int index;

	for (index = 0; to_be_freed[index] != NULL; index++)
		free(to_be_freed[index]);
	free(to_be_freed);
}
