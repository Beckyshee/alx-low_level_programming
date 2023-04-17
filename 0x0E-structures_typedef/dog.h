#ifndef DOG
#define DOG
/**
 * struct dog - is a structure for basic info on a dog object
 * @name: the name of a dog
 * @age: the age of a dog
 * @owner: the owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
