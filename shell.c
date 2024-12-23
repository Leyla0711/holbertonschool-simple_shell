/* shell.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command) {
    pid_t pid = fork();  /* Fork a child process */

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        /* In the child process, execute the command */
        char *args[2];  /* Declare the array here */

        args[0] = command;  /* Assign the first element */
        args[1] = NULL;      /* Set the last element to NULL */

        execvp(command, args);  /* Execute the command */
        
        /* If execvp fails */
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);  /* Wait for the child process to finish */
    }
}

