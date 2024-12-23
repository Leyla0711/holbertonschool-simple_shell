#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

/* Function to execute a command */
int execute_command(char *command)
{
    /* Prepare the argument list for execve */
    char *args[2];  /* Declare the array with two elements */
    args[0] = command;  /* First element is the command */
    args[1] = NULL;  /* NULL to indicate the end of the arguments */

    if (execve(command, args, NULL) == -1)
    {
        /* Command not found */
        perror("./hsh");
        exit(EXIT_FAILURE);
    }
    return 0;
}

