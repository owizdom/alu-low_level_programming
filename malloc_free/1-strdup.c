#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, NULL if str is NULL or the
 * allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
