#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Declare the function */
void execute_command(char *command);

#endif  /* SHELL_H */

