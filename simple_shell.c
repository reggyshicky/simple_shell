#include "simple_shell.h"
/**
 * main - Entry of the program
 * @ac: argument count
 * @av: argument vector
 * @env: double pointer to current environment
 * Return: 0 (EOF) after pressing Ctrl + D
 */
int main(int ac, char **av, char **env)
{
	char *l, *new_l;
	size_t length = 0;
	ssize_t lsize;
	char **tkn_array;
	int cmdn = 0;

	(void)ac, (void)av;
	while (1)
	{
		l = NULL;
		length = 0;
		cmdn++;
		if (isatty(STDIN_FILENO) == 1)
			printprompt();
		signal(SIGINT, control_c);
		lsize = getline(&l, &length, stdin);
		if (lsize == EOF || lsize == -1)
			return (control_d(l));
		if (l[0] == '\n')
		{
			free(l);
			continue;
		}
		new_l = rea_lloc(l);
		if (new_l == NULL)
		{
			free(l);
			return (0);
		}
		tkn_array = str_tkn(new_l);
		if (tkn_array == NULL)
		{
			free(l);
			free(new_l);
			return (0);
		}
		exec_cmd(tkn_array, env, av, l, new_l, cmdn);
		free_everything(l, new_l, tkn_array);
	}
}
