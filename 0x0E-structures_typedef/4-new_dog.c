#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * new_dog - is a function that creates a new dog
 * @name: name of the dog
 * @age: age of the dog 
 * @owner: owner of the dog
 * Return: pointer to new_dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int a = 0;
	int b = 0;
	int d;
	dog_t *pdog;

	while (name[a] != '\0')
		a++;
	while (owner[b] != '\0')
		b++;

	pdog= malloc(sizeof(dog_t));
	if (pdog == NULL)
	{
		free(pdog);
		return (NULL);
	}
	pdog->name = malloc(a * sizeof(pdog->name));
	if (pdog->name == NULL)
	{
		free(pdog->name);
		return (NULL);
	}
	for (d = 0; d <= a; d++)
		pdog->name[d] = name[d];
	pdog->age = age;
	pdog->owner = malloc(b * sizeof(pdog->owner));
	if (pdog->owner == NULL)
	{
		free(pdog->owner);
		free(pdog->name);
		free(pdog);
		return (NULL);
	}
	for (d = 0; d <= b; d++)
		pdog->owner[d] = owner[d];
	return (pdog);
}
