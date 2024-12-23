#ifndef SHELL_H
#define SHELL_H

#include <stddef.h> // Include to use size_t

/* Function declarations */
void prompt(void);                          // Function to display prompt
void execute_command(char *command);        // Function to execute a command
ssize_t read_input(char **command, size_t *len); // Function to read input

#endif

