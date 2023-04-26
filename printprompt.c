#include "simple_shell.h"

/**
 * printprompt - prints the shell prompt
 */
void printprompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
