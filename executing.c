#include "simple_shell.h"

/**
 * exec_cmd - executes an input cmd
 * @arr: pointer to arr of inputs commands
 * @env: double pointer to envoiron var
 * @v: arg vector
 * @l: input from user
 * @new_l: input without \n
 * @cmdn: no. of input cmds
 * Return: -1 failure, 0 success
 */
int exec_cmd(char **arr, char **env, char **v, char *l, char *new_l, int cmdn)
{
	pid_t our_pid;
	char *cant;
	int signal;
	struct stat statuses;

	if (arr == NULL || *arr == NULL || v == NULL || *v == NULL)
		return (-1);
	if (env == NULL || *env == NULL)
		return (-1);
	if (inbuilts(arr, env, l, new_l, cmdn) == 0)
		return (0);
	our_pid = fork();
	if (our_pid == -1)
	{
		write(STDOUT_FILENO, "forking error", 13);
		return (-1);
	}
	if (our_pid == 0)
	{
		if (arr[0][0] == '/')
		{
			if (stat(arr[0], &statuses) == -1)
				error_hand(v, arr, cmdn, l, new_l);
			if (access(arr[0], X_OK) == -1)
				error_hand(v, arr, cmdn, l, new_l);
			execve(arr[0], arr, NULL);
		}
		else
		{
			cant = pathhand(arr[0], env);
			if (cant == NULL)
				error_hand(v, arr, cmdn, l, new_l);
			else
				execve(cant, arr, NULL);
		}
	}
	else
		wait(&signal);
	return (0);
}
