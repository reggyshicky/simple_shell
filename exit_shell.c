#include "simple_shell.h"

/**
 * exit_shell - executes the exit command
 * @arr: an array of command inputs
 * @l: input from the user
 * @new_l: user's input having newline trunc
 * @cmd_num: counts the number of commands entered
 * Return: 0 (success), exit code
 */

int exit_shell(char **arr, char *l, char *new_l, int cmd_num)
{
	int n, k = 0;
	char *cmdcount;

	if (arr[1] == NULL)
	{
		free_everything(l, new_l, arr);
		exit(2);
	}
	else
	{
		n = atois(arr[1]);
		if (n == -1)
		{
			cmdcount = _printint(cmd_num);
			write(STDERR_FILENO, arr[0], 7);
			write(STDERR_FILENO, cmdcount, str_len(cmdcount));
			write(STDERR_FILENO, ": exit: cmd not found!: ", 24);
			while (arr[1][k] != '\0')
				k++;
			write(STDOUT_FILENO, arr[1], k);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		free_everything(l, new_l, arr);
		_exit(n);
	}
}
