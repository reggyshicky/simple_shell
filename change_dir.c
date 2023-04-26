#include "simple_shell.h"

/**
 * change_dir - changes directory
 * @arr: double pointer to array of cmd inputs
 * @env: double pointer to the environment var
 * Return: 0 for success
 */
int change_dir(char **arr, char **env)
{
	int k = 0;
	char cw_dir[1024];
	char *dir_new;

	if (arr[1] == NULL)
	{
		if (chdir(get_env("ROOT", env)) == -1)
		{
			perror(arr[0]);
			write(STDERR_FILENO, "cd: cannot cd to root\n", 22);
		}
	}
	else
	{
		getcwd(cw_dir, 1024);
		while (cw_dir[k] != '\0')
			k++;
		cw_dir[k++] = '/';
		cw_dir[k] = '\0';
		dir_new = str_concat(cw_dir, arr[1]);
		if (dir_new == NULL)
			return (0);
		if (chdir(dir_new) == -1)
		{
			perror(arr[0]);
			write(STDERR_FILENO, "DIR cant be found\n", 18);
		}
		free(dir_new);
	}
	return (0);
}
