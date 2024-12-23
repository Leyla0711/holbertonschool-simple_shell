#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>  /* Include for pid_t */
#include <sys/wait.h>   /* Include for wait() */
#include <unistd.h>      /* Include for fork(), execve(), etc. */

/* Function declarations */
void prompt(void);  /* Declaration of the prompt function */
void execute_command(char *command);  /* Ensure the return type is void */

#endif /* SHELL_H */

