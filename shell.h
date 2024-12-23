#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>  /* Include for pid_t */
#include <sys/wait.h>   /* Include for wait() */

/* Function prototype for command execution */
void execute_command(char *command);  /* Ensure the return type is void */

#endif /* SHELL_H */

