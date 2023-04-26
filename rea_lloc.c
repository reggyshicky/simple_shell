#include "simple_shell.h"

/**
 * rea_lloc - memory reallocation for char
 * @d: pointer to an array of strings
 * Return: pointer to the reallocated mem
 */
char *rea_lloc(char *d)
{
	int k = 0;
	char *new_pointer;

	if (d == NULL)
		return (NULL);

	while (*(d + k) != '\n')
		k++;
	new_pointer = malloc(sizeof(char) * k + 1);
	if (new_pointer == NULL)
		return (NULL);
	k = 0;
	while (*(d + k) != '\n')
	{
		*(new_pointer + k) = *(d + k);
		k++;
	}
	*(new_pointer + k) = '\0';
	return (new_pointer);
}
