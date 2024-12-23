/* shell.h */
#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>  /* For ssize_t and size_t */
#include <stdio.h>   /* For perror */

/* Function declarations */
void prompt(void);
ssize_t read_input(char **command, size_t *len);
void execute_command(char *command);

#endif

