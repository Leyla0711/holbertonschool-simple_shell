#include "shell.h"
#include <stddef.h>   /* For NULL */
#include <stdio.h>    /* For perror */
#include <stdlib.h>   /* For exit, free */

int main(void)
{
    char *command = NULL;

    prompt();  /* Display prompt */
    command = read_input();  /* Get user input */

    if (command == NULL)
    {
        perror("read_input failed");
        exit(1);  /* Exit with an error code if command allocation fails */
    }

    execute_command(command);  /* Execute the command */
    free(command);  /* Free memory allocated for the command */

    return (0);
}

