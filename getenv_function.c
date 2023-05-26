#include "header.h"

/**
 * getenv_function - get the contents of an environment variable.
 *
 * @variable_env: the environment variable.
 *
 * Return: return NULL.
 */
char *getenv_function(char *variable_env)
{
size_t size;
int index;

size = f_strlen(variable_env);

for (index = 0; environ[index] != NULL; index++)
{

if (f_strncmp(environ[index], variable_env, size) == 0
		&& environ[index][size] == '=')
return (environ[index] + size + 1);

}

return (NULL);
}
