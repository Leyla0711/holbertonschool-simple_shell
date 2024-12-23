#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command) {
    pid_t pid = fork();  /* Create a child process */

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  /* Child process */
        char *args[2];  /* Command argument array */
        args[0] = command;
        args[1] = NULL;
        
        if (execve(command, args, NULL) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {  /* Parent process */
        wait(NULL);  /* Wait for the child process to finish */
    }
}

