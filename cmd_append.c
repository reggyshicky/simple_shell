#include "simple_shell.h"
/**
 * cmd_append - joins together a dir path and cmd name
 * @path_dir: Directory path to join
 * @cmd: Command name to join
 * Return: Pointer to the joined command path
 */

char *cmd_append(char *path_dir, char *cmd)
{
	int dir_len = 0;
	int cmd_len = 0;
	int f = 0;
	int g = 0;
	char *cmdpath = NULL;

	if (path_dir == NULL || cmd == NULL)
		return (NULL);

	cmd_len = str_len(cmd);
	dir_len = str_len(path_dir);
	cmdpath = malloc(cmd_len + dir_len + 2); /* 2 rep the '/' and '\0' */

	if (cmdpath == NULL)
		return (NULL);
	while (path_dir[f] != '\0')
	{
		cmdpath[f] = path_dir[f];
		f++;
	}
	while (path_dir[f - 1] != '/')
	{
		cmdpath[f] = '/';
		f++;
	}
	while (cmd[g] != '\0')
	{
		cmdpath[f + g] = cmd[g];
		g++;
	}
	cmdpath[f + g] = '\0';
	return (cmdpath);
}
