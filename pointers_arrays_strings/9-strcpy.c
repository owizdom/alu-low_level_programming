#include "main.h"

/**
 * _strcpy - copies a string, including its terminating null byte, to a
 * buffer
 * @dest: the buffer to copy into
 * @src: the string to copy
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
