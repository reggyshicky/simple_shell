#include "simple_shell.h"

/**
 * inbuilts - checks if cmd entered exists
 * @arr: double Pointer to array of cmds to execute
 * @env: the environment va
 * @l: entry from user
 * @new_l: entry from user without \n
 * @cmd_num: counts no of cmd args
 * Return: 0 if cmd exists. 1 when absent
 */
int inbuilts(char **arr, char **env, char *l, char *new_l, int cmd_num)
{
	if (arr == NULL || *arr == NULL)
		return (1);
	if (env == NULL || *env == NULL)
		return (1);
	if (str_cmp((arr[0]), "exit") == 0)
		return (exit_shell(arr, l, new_l, cmd_num));
	else if (str_cmp((arr[0]), "cd") == 0)
		return (change_dir(arr, env));
	else if (str_cmp((arr[0]), "env") == 0)
		return (_env(env));
	else
		return (1);
}
