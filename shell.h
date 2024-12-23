#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>  // Include for pid_t
#include <sys/wait.h>   // Include for wait()

void prompt(void);
void execute_command(char *command);  // Ensure the return type is void

#endif /* SHELL_H */

