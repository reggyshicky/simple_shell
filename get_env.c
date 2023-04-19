#include "simple_shell.h"

/**
 * get_env - Getting contents of a global variable
 * @globvar: Variable whose value is to be retrieved
 *
 * Return: Pointer to globvar content, NULL if it fails
 */

char *get_env(char *globvar)
{
	int r = 0;
	const char delim = "=";
	char *env_tkn;
	char *env_dup;
	char *env_tkndup;

	if (globvar != NULL)
	{
		if (environ == NULL)
			return (NULL);

		env_dup = str_dup(environ[r]);
		while (env_dup != NULL)
		{
			env_tkn = strtok(env_dup, delim);
			if (str_cmp(env_tkn, globvar) == 0)
			{
				env_tkn = strtok(NULL, delim);
				env_tkndup = str_dup(env_tkn);
				free(env_dup);
				return (env_tkndup);
			}
			r++;
			free(env_dup);
			env_dup = str_dup(environ[r]);
		}
	}
	return (NULL);
}
