#include "simple_shell.h"

/**
 * _env - deals with environmental variables
 * @env: double pointer to environmental variables
 * Return: 0 (success)
 */

int _env(char **env)
{
	int k = 0;
	int len = 0;

	while (env[k] != NULL)
	{
		len = str_len(env[k]);
		write(STDOUT_FILENO, env[k], len);
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
	return (0);
}
