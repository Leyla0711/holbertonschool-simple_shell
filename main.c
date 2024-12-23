#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 1024

/* Function to display the prompt */
void prompt(void)
{
    printf("$ ");
}

/* Main function */
int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;

    while (1)
    {
        prompt();  /* Display the prompt */

        /* Read user input */
        read = getline(&command, &len, stdin);

        if (read == -1)
        {
            /* EOF (Ctrl+D) or error reading input */
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }

        /* Remove the newline character from the command input */
        command[strcspn(command, "\n")] = 0;

        /* If command is empty, continue to the next loop */
        if (strlen(command) == 0)
        {
            continue;
        }

        /* Create a child process to execute the command */
        pid = fork();

        if (pid == -1)
        {
            /* Error in fork() */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)  /* Child process */
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
        }
        else  /* Parent process */
        {
            /* Wait for the child process to finish */
            waitpid(pid, &status, 0);
        }
    }

    free(command);
    return (0);
}

