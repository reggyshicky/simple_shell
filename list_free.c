#include "simple_shell.h"

/**
 * list_free - frees alinked list
 * @h: head of linked list
 * Return: nothing
 */
void list_free(path_t *h)
{
	path_t *nxtnod;

	while (h != NULL)
	{
		nxtnod = h->next;
		free(h->dir);
		free(h);
		h = nxtnod;
	}
}
