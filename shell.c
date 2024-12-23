/* shell.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *command)
{
    pid_t pid = fork();  /* Create a new process */

    if (pid < 0)  /* Fork failed */
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)  /* Child process */
    {
        char *args[2];
        args[0] = command;  /* Set the command */
        args[1] = NULL;  /* Null-terminate the argument array */

        if (execvp(command, args) == -1)  /* Execute the command */
        {
            perror("execvp failed");
            exit(1);
        }
    }
    else  /* Parent process */
    {
        wait(NULL);  /* Wait for the child to finish */
    }
}

