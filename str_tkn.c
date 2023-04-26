#include "simple_shell.h"
#define STRING_DELIM " \t\0"

/**
 * str_tkn - divides user input int tokens
 * @l: user's input
 * Return: array of tokens
 */
char **str_tkn(char *l)
{
	int k = 0;
	int tkn_index = 0;
	char **tkn_arr;
	char *tkn, *tkncpy;

	if (l == NULL)
		return (NULL);
	while (*(l + k) != '\0')
	{
		if (l[k] != ' ' && (l[k + 1] == ' ' || l[k + 1] == '\0'
					|| l[k + 1] == '\t'))
			tkn_index++;
		k++;
	}

	k = 0;
	tkn_arr = malloc(sizeof(char *) * (tkn_index + 1));
	if (tkn_arr == NULL)
		return (NULL);
	tkn = strtok(l, STRING_DELIM);
	while (tkn != NULL)
	{
		tkncpy = str_dup(tkn);
		if (tkncpy == NULL)
		{
			free(tkn_arr);
			return (NULL);
		}
		*(tkn_arr + k) = tkncpy;
		tkn = strtok(NULL, STRING_DELIM);
		k++;
	}
	*(tkn_arr + k) = NULL;
	return (tkn_arr);
}
