#ifndef SHELL_H
#define SHELL_H

/*INCLUDES*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*Macros*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*Function*/
char *interpret_line(void);
char **divide_line(char *line);
int exec_args(char **args);
int create_process(char **args);
char *r_stream(void);
int my_own_cd(char **args);
int my_own_exit(char **args);
int my_own_env(char **args);
int my_own_help(char **args);
void interactive_mode(void);
void non_interactive_mode(void);

#endif
