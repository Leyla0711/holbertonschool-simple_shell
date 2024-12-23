#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>    /* Include for stdin, printf, and getline */
#include <stdlib.h>   /* Include for malloc, free */
#include <stddef.h>   /* Include for size_t and ssize_t */

/* Function declarations */
void prompt(void);  /* Function to display prompt */
void execute_command(char *command); /* Function to execute a command */
ssize_t read_input(char **command, size_t *len); /* Function to read input */

#endif

