#include "shell.h"


void non_interactive_mode(void)
{
 char *line;
 char **args;
 int status = -1;

 do {
  line = r_stream();
  args = divide_line(line); /* tokenize line */
  status = exec_args(args);
  /* avoid memory leaks */
  free(line);
  free(args);
  /* exit with status */
  if (status >= 0)
  {
   exit(status);
  }
 } while (status == -1);
}