#include "simple_shell.h"
/**
 * find_cmdinputs - Displays inputs from the user in an array
 * @element: The string input by the user
 * @args: Stores the args extracted by the function
 * Return: length of args(array)
 */

int find_cmdinputs(char *element, char **args)
{
	char *sub_tokens; /*stores subsequent tokens*/
	char *_track = element; /*tracking our pos in the input str*/
	char *cmd; /*stores the 1st token, args[0]*/

	int l = 0;

	cmd = strtok(element, "\n\t\r");
	args[l] = cmd;

	while (_track != NULL)
	{
		++l;
		sub_tokens = strtok(NULL, "\n\t\r");
		_track = sub_tokens; /*checks for more tokens in the next loop*/
		args[l] = sub_tokens;
	}
	args[l] = NULL; /*shows end of the array*/
	return (l);
}
