#include "simple_shell.h"

/**
 * atois - converts ASCII to integer
 * @s: pointer to the string to be converted
 * Return: integer
 */
int atois(char *s)
{
	int k, m = 0;
	int tenth = 1;
	unsigned int int_ger = 0;
	int isneg_fig = 0;
	int neg_fig = 0;
	int pos_fig = 0;

	while (s[m] != '\0')
	{
		if (s[m] > '9' || s[m] < '0')
			return (-1);
		m++;
	}
	while ((s[k] > '9' || s[k] < '0') && s[k] != '\0')
	{
		if (s[k] == '-')
			neg_fig++;
		if (s[k] == '+')
			pos_fig++;
		k++;
	}
	if (s[k] == '\0')
		return (0);
	if ((neg_fig % 2) != 0)
		isneg_fig = 1;
	tenth = tens_point(k, s);
	while (s[k] >= '0' && s[k] <= '9')
	{
		int_ger += ((s[k] - '0') * tenth);
		tenth /= 10;
		k++;
	}
	if (isneg_fig == 1)
		int_ger *= -1;
	return ((int) int_ger);
}
