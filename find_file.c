#include "simple_shell.h"
/**
 * find_file - function checks if file exists or not
 * @p_name: pointer to the pathname of the file
 * Return: 0 if file exists, -1 if it does not
 */

int find_file(char *p_name)
{
	int fd; /* file descriptor*/

	fd = open(p_name, O_RDONLY); /*Read only mode*/
	if (fd == -1)
	{
		return (-1);
	}
	else
	{
		close(fd);
		return (0);
	}
}
