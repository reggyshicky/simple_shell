#include "simple_shell.h"

/**
 * str_dup - duplciates string
 * @s: string to duplicate
 * Return: pointer to the duplicated string
 */
char *str_dup(char *s)
{
	int r = 0;
	int le_n = 0;
	char *str;

	if (s == NULL)
		return (NULL);
	while (*(s + r) != '\0')
	{
		le_n++;
		r++;
	}

	r = 0;
	str = malloc(sizeof(char) * le_n + 1);
	if (str == NULL)
		return (NULL);
	while (*(s + r) != '\0')
	{
		*(str + r) = *(s + r);
		r++;
	}
	*(str + r) = '\0';
	return (str);
}
