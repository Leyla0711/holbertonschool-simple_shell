#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function to execute a command */
void execute_command(char *command);  /* Declaration */

#endif  /* SHELL_H */

