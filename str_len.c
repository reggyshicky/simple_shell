#include "simple_shell.h"

/**
 * str_len - Returns the length of the arguments
 * @s: pointer to the string
 *
 * Return: length of the argument
 */

int str_len(const char *s)
{
	int length = 0;

	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
