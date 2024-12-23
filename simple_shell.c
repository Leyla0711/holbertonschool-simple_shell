#include "shell.h"
#include <stdio.h>   /* For perror */
#include <stdlib.h>  /* For exit, malloc, free */
#include <sys/types.h>  /* For pid_t */
#include <unistd.h>  /* For fork, execvp */
#include <sys/wait.h>  /* For wait */

void execute_command(char *command) {
    pid_t pid = fork();  /* Fork a child process */

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        /* In the child process, execute the command */
        
        /* Dynamically allocate memory for the argument array */
        char *args[2];
        args[0] = command;
        args[1] = NULL;  /* Null-terminate the argument list */

        execvp(command, args);  /* Execute the command */
        
        /* If execvp fails */
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);  /* Wait for the child process to finish */
    }
}

