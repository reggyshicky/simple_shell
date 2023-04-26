#include "simple_shell.h"

/**
 * str_cmp - compares two string
 * @s1: first string
 * @s2: second string
 * Return: if s1<s2, (-), s1>s2 (+), s1 = s2 (0)
 */
int str_cmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	else if (*s1 > *s2)
		return ((int)(*s1 - *s2));
	else
		return ((int)(*s1 - *s2));
}
