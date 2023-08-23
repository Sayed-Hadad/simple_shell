#include "shell.h"

/**
 *create_process - Create and execute a new process
 *@args: Array of strings containing the command and its flags
 *
 *Return: 1 if successful, 0 otherwise.
 */
int create_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in create_process: child process");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error in create_process: forking");
	}
	else
	{
		do { waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
