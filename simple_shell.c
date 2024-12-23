/* simple_shell.c */
#include "shell.h"
#include <stdlib.h>  /* For free and malloc */
#include <stdio.h>   /* For perror */

int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    /* Prompt user for input */
    prompt();

    nread = read_input(&command, &len);  /* Correct function call */
    
    if (nread == -1) {
        perror("read_input failed");
        free(command);  /* Make sure to free memory if an error occurs */
        exit(1);
    }
    
    /* Execute the command */
    execute_command(command);

    /* Free memory allocated for the command */
    free(command);

    return 0;
}

