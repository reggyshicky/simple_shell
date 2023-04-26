#include "simple_shell.h"

/**
 * _printint - prints an int
 * @number: num to change to str
 * Return: no. of characters on STDOUT
 */

char *_printint(int number)
{
	int tenth = 1;
	int k = 0;
	int tenth_int = number;
	char *int_ger;

	int_ger = malloc(34);
	if (int_ger == NULL)
		return (NULL);
	if (number == 0)
	{
		int_ger[k] = 0 + '0';
		return (int_ger);
	}
	number = number / 10;

	while (tenth != 0)
	{
		int_ger[k] = (tenth_int / tenth) + '0';
		tenth_int = tenth_int % tenth;
		tenth /= 10;
		k++;
	}
	int_ger[k] = '\0';
	return (int_ger);
}

