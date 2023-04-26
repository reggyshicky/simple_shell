#include "simple_shell.h"
/**
 * appendnode - append path var to an empty path_t
 * @s: pointer to path var
 * @lists: pointer to path_t list
 * Return: pointer to the new list
 */
path_t *appendnode(char *s, path_t *lists)
{
	char *directory;
	path_t *pointer, *h;
	int k = 0, n = 0, sup = 0, dlen = 0;

	if (s == NULL || lists == NULL)
		return (NULL);
	h = lists;
	pointer = h;
	while (pointer != NULL)
	{
		if (s[k] == ':' || s[k] == '\0')
		{
			if (s[k] != '\0')
				k++;
			directory = malloc(sizeof(char) * dlen + 2);
			if (directory == NULL)
				return (NULL);
			while (s[sup] != ':' && s[sup] != '\0')
			{
				directory[n] = s[sup];
				sup++;
				n++;
			}
			directory[n++] = '/';
			directory[n] = '\0';
			sup = k;
			n = 0;
			pointer->dir = directory;
			pointer = pointer->next;
		}
		else
		{
			dlen++;
			k++;
		}
	}
	return (h);
}
