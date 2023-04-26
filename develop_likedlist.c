#include "simple_shell.h"

/**
 * develop_likedlist - forms an empty path based on arguments
 * @s: pointer to the formed path variable
 * Return: pointer to the path_t struct
 */

path_t *develop_likedlist(char *s)
{
	int _nodes = 1;
	int k = 0;
	path_t *last, *h, *temp, *_node;

	temp = malloc(sizeof(path_t));
	if (temp == NULL)
		return (NULL);
	h = temp;
	last = malloc(sizeof(path_t));
	if (last == NULL)
	{
		free(temp);
		return (NULL);
	}
	last->next = NULL;
	while (s[k] != '\0')
	{
		if (s[k] == ':')
			_nodes++;
		k++;
	}
	while ((_nodes - 2) > 0)
	{
		_node = malloc(sizeof(path_t));
		if (_node == NULL)
		{
			free(temp);
			free(last);
			return (NULL);
		}
		temp->next = _node;
		temp = temp->next;
		_nodes--;
	}
	temp->next = last;
	return (h);
}
