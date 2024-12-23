#include "shell.h"
#include <stdio.h>    /* for perror */
#include <stdlib.h>   /* for exit */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function to execute a command */
void execute_command(char *command) {
    pid_t pid = fork();  /* Create a child process */

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  /* Child process */
        /* Dynamically allocate space for the argument array */
        char *args[2];  /* Declare an array to hold arguments */
        args[0] = command;  /* Set first argument to the command */
        args[1] = NULL;  /* Null-terminate the argument list */
        
        if (execve(command, args, NULL) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {  /* Parent process */
        wait(NULL);  /* Wait for the child process to finish */
    }
}

