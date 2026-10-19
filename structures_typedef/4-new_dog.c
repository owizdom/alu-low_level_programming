#include "dog.h"
#include <stdlib.h>

/**
 * copy_string - returns a newly allocated copy of a string
 * @str: the string to copy
 *
 * Return: a pointer to the copy, NULL if the allocation fails
 */
char *copy_string(char *str)
{
	char *copy;
	unsigned int len;
	unsigned int i;

	len = 0;
	while (str[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

/**
 * new_dog - creates a new dog with its own copies of name and owner
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the name of the dog's owner
 *
 * Return: a pointer to the new dog, NULL if name or owner is NULL or an
 * allocation fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = copy_string(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = copy_string(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	d->age = age;
	return (d);
}
