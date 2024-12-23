#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void prompt(void)
{
    printf("Shell> ");  /* Display a prompt for the user to enter a command */
}

void execute_command(char *command)
{
    if (fork() == 0) /* Child process */
    {
        char *args[] = {command, NULL}; /* Prepare the command for execvp */
        execvp(command, args);  /* Execute the command */
        perror("execvp failed"); /* If execvp fails, print an error */
        exit(1);  /* Exit if execvp fails */
    }
    else
    {
        wait(NULL); /* Parent process waits for child to finish */
    }
}

ssize_t read_input(char **command, size_t *len)
{
    ssize_t nread = getline(command, len, stdin); /* Read input from stdin */
    if (nread == -1)
    {
        return -1; /* If input reading fails, return -1 */
    }
    return nread;
}

