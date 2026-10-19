#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog and who it belongs to
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the name of the dog's owner
 *
 * Description: holds the basic information about one dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *copy_string(char *str);

#endif /* DOG_H */
