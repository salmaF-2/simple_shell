#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strncmp - compares two strings
 * @str1: first string
 * @str2: second string
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, -1 if not
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	return (-1);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i = 0;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * sigintHandler - handles the SIGINT signal
 * @sig_num: signal number
 * Return: void
 */

void sigintHandler(int sig_num)
{
	(void)sig_num;
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
#include "main.h"


/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * ffree - frees a double pointer
 * @ptr: double pointer to be freed
 * Return: void
 */

void ffree(char **ptr)
{
	char **temp = ptr;

	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	if (temp != NULL)
		free(temp);
	ptr = NULL;
}

/**
 * p_free - frees a pointer
 * @ptr: pointer to be freed
 * Return: void
 */

void p_free(char *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}
