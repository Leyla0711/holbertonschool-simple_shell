/* main.c */
#include "shell.h"
#include <stdlib.h>
#include <stdio.h>  /* For perror and printf */

int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    /* Prompt user for input */
    prompt();
    
    nread = read_input(&command, &len);  /* Correct function call */
    if (nread == -1)
    {
        perror("read_input failed");
        exit(1);
    }
    
    /* Execute the command */
    execute_command(command);

    /* Free memory allocated for the command */
    free(command);

    return 0;
}

