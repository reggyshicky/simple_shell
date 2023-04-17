#include "simple_shell.h"

/**
 * prompt_print - prints prompt to the STDIN
 * @prmpt: pointer to the string to print on terminal
 * @size: size of the string
 *
 * Return: 0 success, -1 failure
 */

int prompt_print(const char *prmpt, size_t size)
{
	int enter = 0; /*file descriptor*/

	if (isatty(STDIN_FILENO)) /*checks whether its a terminal*/
	{
		enter = write(1, prmpt, size);
		if (enter == -1)
			return (-1);
	}
	else
		return (0);
}
