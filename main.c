#include "simple_shell.h"

/**
 * main - Entry of the simple_shell program
 * Return: 0 (success)
 */

int main(void)
{
	signed int bts_read = 0; /*return for getline() or bytes read*/
	unsigned int buff_size = 0;
	char *input = NULL, *args[25];
	int index = 1, pathstat = 0, filestat = 0, execstat = 0, inbltstat = 0;

	prompt_print("$ ", 2);
	bts_read = getline(&input, &buff_size, stdin);
	while (bts_read != -1)
	{
		if (*input != '\n')
		{
			find_cmdinputs(input, args);
			if (args[0] != NULL)
			{
				filestat = find_file(args[0]);
				if (filestat != 0)/*no file*/
				{
					pathstat = find_fullpath(args);
					if (pathstat == 0)
						execstat = _exec(args), free(input), free(*args);
					else
					{
					inbltstat = exit_args(args, execstat);
					if (inbltstat != 0)
						execstat = prnt_err(args, index), free(input);
					}
				}
				else/*File present*/
					execstat = _exec(args), free(input);
			}
			else
				free(input);
		}
		else if (*input == '\n')
			free(input);
		input = NULL, index++;
		prompt_print("$ ", 2), bts_read = getline(&input, &buff_size, stdin);
	}
	memfree(input);
	return (execstat);
}
