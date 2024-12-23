#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   /* Include for fork and execvp */
#include <sys/wait.h> /* Include for wait */
#include "shell.h"

void prompt(void)
{
    printf("Shell> ");  /* Display a prompt for the user to enter a command */
}

void execute_command(char *command)
{
    pid_t pid = fork(); /* Create a new process */
    
    if (pid == -1) /* Check if fork failed */
    {
        perror("fork failed");
        exit(1);
    }
    
    if (pid == 0) /* Child process */
    {
        /* Prepare the command arguments for execvp */
        char *args[2];  /* We know there will be at least two elements: command and NULL */
        args[0] = command;  /* The command itself */
        args[1] = NULL;     /* NULL terminate the array for execvp */
        
        if (execvp(command, args) == -1)  /* Execute the command */
        {
            perror("execvp failed"); /* If execvp fails, print an error */
            exit(1);  /* Exit child process if execvp fails */
        }
    }
    else /* Parent process */
    {
        wait(NULL); /* Wait for child process to finish */
    }
}

ssize_t read_input(char **command, size_t *len)
{
    return getline(command, len, stdin); /* getline returns ssize_t */
}

