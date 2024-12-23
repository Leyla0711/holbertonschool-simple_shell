#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  // Include for pid_t
#include <sys/wait.h>   // Include for wait()

#include "shell.h"

void prompt(void)
{
    printf("$ ");  // Display the prompt
}

void execute_command(char *command)  // Change return type to void
{
    pid_t pid = fork();  // Create a child process

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        char *args[] = {command, NULL};  // Command argument array
        if (execve(command, args, NULL) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {  // Parent process
        wait(NULL);  // Wait for the child process to finish
    }
}

