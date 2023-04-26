#include "simple_shell.h"

/**
 * tkn_free - frees the tokens
 * @token_array: double pointer to tokens for freeing
 */

void tkn_free(char **token_array)
{
	int k = 0;

	while (token_array[k] != NULL)
	{
		free(token_array[k]);
		k++;
	}
	free(token_array[k]);
}
