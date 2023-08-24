#include "shell.h"

/**
 *interactive_mode - Function that runs the shell
 *
 *Return: void
 */
void interactive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("($) ");
		line = interpret_line();
		args = divide_line(line);
		status = exec_args(args);
		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
