#include "simple_shell.h"

/**
 * pathhand - loops through path var and concats cmd
 * @s: pointer to path var
 * @env: double pointer to env var
 * Return: pointer to concat s
 */

char *pathhand(char *s, char **env)
{
	char *cant, *route;
	path_t *lists, *temp;
	struct stat mk;

	if (s == NULL || env == NULL || *env == NULL)
		return (NULL);
	route = get_env("PATH", env);
	if (route == NULL)
	{
		write(STDERR_FILENO, "No path available", 17);
		_exit(0);
	}
	lists = develop_likedlist(route);
	if (lists == NULL)
	{
		write(STDERR_FILENO, "faulty path", 11);
		_exit(0);
	}
	lists = appendnode(route, lists);
	temp = lists;
	while (temp != NULL)
	{
		if (route[0] == ':')
			cant = str_concat("./", s);
		else
			cant = str_concat(temp->dir, s);
		if (cant == NULL)
			return (NULL);
		if (stat(cant, &mk) == 0 && access(cant, X_OK) == 0)
		{
			list_free(lists);
			return (cant);
		}
		temp = temp->next;
		free(cant);
	}
	list_free(lists);
	return (NULL);
}
