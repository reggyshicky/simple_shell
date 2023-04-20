#include "simple_shell.h"

/**
 * find_fullpath - searches for executable path of user input cmd
 * @args: Array of strings with user's input cmd & args
 * Return: 0 success
 */

int find_fullpath(char **args)
{
	char *globpath = NULL;/*holds value of PATH env variable*/
	char *globdup = NULL; /* a duplicate of globpath*/
	char *path_dir = NULL; /*Holds each dir in globpath*/
	char *cmd_path = NULL; /*fullpath to the executable being searched for*/
	char *path_candidates[140];
	int n = 0;
	int file_existstat = -1;

	globpath = get_env("PATH");
	if (globpath == NULL)
		return (-1);

	globdup = str_dup(globpath);
	path_dir = strtok(globdup, ":");
	if (path_dir == NULL)
		return (-1);
	free(globpath);

	while (path_dir != NULL && file_existstat == -1)
	{
		cmd_path = cmd_append(path_dir, args[0]);
		path_candidates[n] = cmd_path;
		file_existstat = find_file(path_candidates[n]);
		path_dir = strtok(NULL, ":");
		n++;
	}
	n--;
	if (file_existat == 0)
	{
		args[0] = path_candidates[n];
		return (0);
	}
	else
	{
		free(path_candidates[n]);
		return (-1);
	}
}
