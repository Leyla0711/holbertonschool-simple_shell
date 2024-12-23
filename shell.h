#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_loop(void);  /* Declare shell_loop */
char *read_input(void);  /* Correct declaration for read_input */
int execute_command(char **args);  /* Declaration for command execution */

#endif /* SHELL_H */

