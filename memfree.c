#include "simple_shell.h"

/**
 * memefree - Frees dynamically allocated memory
 * @element: User's input string
 */

void memfree(char *element)
{
	if (isatty(STDIN_FILENO)) /*checks if it is a terminal*/
	{
		_putchar('\n');
		free(element);
	}
	if (!isatty(STDIN_FILENO))
		free(element);
}
