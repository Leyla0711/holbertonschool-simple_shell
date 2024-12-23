#ifndef SHELL_H
#define SHELL_H

#include <stddef.h> /* For NULL */
#include <stdlib.h> /* For free */
#include <stdio.h>  /* For perror */

void prompt(void);
char *read_input(void);
void execute_command(char *command);

#endif /* SHELL_H */

