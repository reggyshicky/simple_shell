#include "simple_shell.h"

/**
 * con_cat - puts together 2 str
 * @cat: pointer to mem alloc to concatenated string
 * @s1: first string
 * @s2: second string
 * Return: pointer to concatenated string
 */
char *con_cat(char *cat, char *s1, char *s2)
{
	int catindex = 0;
	int strindex = 0;

	while (*(s1 + strindex) != '\0')
	{
		*(cat + catindex) = *(s1 + strindex);
		catindex++;
		strindex++;
	}

	strindex = 0;

	while (*(s2 + strindex) != '\0')
	{
		*(cat + catindex) = *(s2 + strindex);
		catindex++;
		strindex++;
	}
	*(cat + catindex) = '\0';
	return (cat);
}
