#include "shell.h"

/**
 * my_own_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int my_own_exit(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (_atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}
