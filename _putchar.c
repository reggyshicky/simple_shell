#include "simple_shell.h"
/**
 * _putchar - writes a character to the standard output
 * @c: The character to print
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
