#include "simple_shell.h"

/**
 * _exec - Executes a command specified in the args
 * @args: double pointer to the cmds and any args passed
 *
 * Return: Always 0 (success)
 */

int _exec(char **args)
{
	pid_t child_pid = 0; /*pid of the child process*/
	int stat_child = 0; /*stores stat of a child process after wait()*/
	int exitstat = 0; /*stores the exitstat of child after cmd exec*/

	child_pid = fork(); /*creating a child process*/
	if (child_pid == -1)
		prompt_print("Error\n", 6);

	else if (child_pid == 0) /*He is the child*/
	{
		exitstat = execve(args[0], args, environ);
		if (exitstat == -1)
		{
			exitstat = 126; /*means cmd couldn't be executed*/
			perror("hsh");
			exit(existat);
		}
		exit(0);
	}
	else /*parent*/
	{
		wait(&stat_child); /*waits for child process to terminate*/
		exitstat = WEXITSTATUS(stat_child);
		return (exitstat);
	}
}
