#include "simple_shell.h"

/**
 * tens_point - finds mult factor of tens
 * @k: counter of where the no begins in str
 * @m: pointer to the string
 * Return: tens multiplier
 */

int tens_point(int k, char *m)
{
	double tenth = 1;

	while (m[k] >= '0' && m[k] <= '9')
	{
		tenth *= 10;
		k++;
	}
	tenth /= 10;
	return ((int) tenth);
}
