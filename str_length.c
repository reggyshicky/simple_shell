#include "simple_shell.h"

/**
 * str_len - finds length of a string
 * @s: string to use
 * Return: length of the string
 */

int str_len(char *s)
{
	int b = 0;
	int le_n = 0;

	if (s == NULL)
		return (-1);
	while (s[b] != '\0')
	{
		le_n = le_n + 1;
		b++;
	}
	return (le_n);
}
