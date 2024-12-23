/* main.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *command = NULL;

    /* Call prompt function to display prompt */
    prompt();

    /* Read user input */
    command = read_input();

    /* Execute the command */
    execute_command(command);

    /* Free allocated memory */
    free(command);
    return 0;
}

