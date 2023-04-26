#include "simple_shell.h"

/**
 * error_hand - Dealing with errors
 * @argv: argument vector
 * @arr: pointer to token array from user
 * @cmdnum: number of cmd inputs
 * @l: user line input
 * @new_l: user input lacking '\n' character
 */
void error_hand(char **argv, char **arr, int cmdnum, char *l, char *new_l)
{
	char *n;

	n = _printint(cmdnum);
	write(STDERR_FILENO, argv[0], str_len(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, n, str_len(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arr[0], str_len(arr[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(n);
	free_everything(l, new_l, arr);
	exit(0);
}
