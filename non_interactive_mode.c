#include "shell.h"

/**
 *non_interactive_mode - Function that runs the shell no interactive
 *
 *Return: void
 */
void non_interactive_mode(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = r_stream();
		args = divide_line(line); /*tokenize line */
		status = exec_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
