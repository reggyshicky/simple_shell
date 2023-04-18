#include "simple_shell.h"

/**
 * exit_args - checks whether entered commnands are inbuilt cmds
 * @args: double pointer to cmd args
 * @exit_status: Current exit status
 *
 * Return: 0 if inbuilt, 1 if cmd is not
 */

int exit_args(char **args, int exit_status)
{
	char *in_builts[2] = {"exit", "env"};

	int l;

	for (l = 0; l < 2; l++)
	{
		if (str_cmp(args[0], in_builts[l]) == 0)
			break;
	}
	if (l == 2)
		return (-1);
	if (str_cmp(in_builts[l], "exit") == 0)
	{
		free(args[0]);
		exit(exit_status);
	}
	if (str_cmp(in_builts[l], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}
