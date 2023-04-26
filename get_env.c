#include "simple_shell.h"

/**
 * get_env - searches for env variables
 * @jina: pointer to the var name
 * @env: double pointer to env var
 * Return: ptr to the env var
 */
char *get_env(const char *jina, char **env)
{
	int k = 0, m = 0;

	if (jina == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[k] != NULL)
	{
		while (env[k][m] == jina[m])
			m++;
		if (env[k][m] == '=')
		{
			m++;
			return (&(env[k][m]));
		}
		k++;
		m = 0;
	}
	write(STDOUT_FILENO, "env var not found!", 18);
	return (NULL);
}
