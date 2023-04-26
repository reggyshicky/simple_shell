#include "simple_shell.h"

/**
 * control_c - handles Ctrl+C
 * @sig: signal input
 */
void control_c(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * control_d - control D handler
 * @lines: users entry
 * Return: 0 success
 */
int control_d(char *lines)
{
	free(lines);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
