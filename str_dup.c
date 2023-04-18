#include "simple_shell.h"

/**
 * str_dup - duplicates a string
 * @s: string to be duplicated
 *
 * Return: pointer to the duplicated string
 */

char *str_dup(char *s)
{
	size_t length;
	size_t m;
	char *dup_str;

	if (s == NULL)
		return (NULL);
	
	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	dup_str = (char *)malloc(sizeof(char) * (length + 1));
	if (dup_str == NULL)
		return (NULL);

	m = 0;
	while (m <= length)
	{
		dup_str(m) = s(m);
		m++;
	}
	return (dup_str);
}
