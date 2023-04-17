#include "simple_shell.h"
/**
 * str_cmp - function that compares two strings
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * Return: 0 if(s1 = s2), negative if (s1 < s2), positive if(s1 >s2)
 */
int str_cmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
