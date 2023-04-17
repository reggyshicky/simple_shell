#include "simple_shell.h"

/**
 * _errorstatus - function that prints error status
 * @q: the number to be printed
 * Return: The error status int
 */

int _errorstatus(int q)
{
	int r = 0; /*counts no. of characters to prints*/

	int digits;

	if (q < 0)
	{
		digits = -q;
		r += _putchar('-');
	}
	else
		digits = q;
	if (digits / 10 != '\0')
		r += _errorstatus(digits / 10);
	r += _putchar(digits % 10 + '0');

	return (r);
}

/**
 * prnt_err - prints error msg if cmd ! found
 * @args: array of args to be entered
 * @tracker: counts no. of times of shell execution
 * Return: status of exit
 */

int prnt_err(char **args, int tracker)
{
	char *non_interaction_mod = "./hsh"; /*non interactive*/
	char *interaction_mod = "hsh"; /*interactive mode*/

	if (isatty(STDIN_FILENO)) /*Checks terminal*/
		write(2, interaction_mod, 3);
	else
		write(2, non_interaction_mod, 5);

	write(2, ": ", 2);
	_errorstatus(tracker);
	write(2, ": ", 2);
	write(2, args[0], str_len(args[0]));
	write(2, ": not found\n", 12);

	return (127); /*common exit status for cmd ! found*/
}
