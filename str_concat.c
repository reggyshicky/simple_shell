#include "simple_shell.h"

/**
 * str_concat - add source str to dest str
 * @s1: first string
 * @s2: second string
 * Return: appended string
 */
char *str_concat(char *s1, char *s2)
{
	char *concatt;
	int le_n1 = 0;
	int le_n2 = 0;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}
	le_n1 = str_len(s1);
	le_n2 = str_len(s2);

	concatt = malloc(sizeof(char) * (le_n1 + le_n2 + 1));
	if (concatt == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (con_cat(concatt, s1, s2));
}
