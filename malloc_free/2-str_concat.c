#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated string
 * @s1: the first string, treated as empty when NULL
 * @s2: the second string, treated as empty when NULL
 *
 * Return: a pointer to the new string, or NULL if the allocation fails
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
