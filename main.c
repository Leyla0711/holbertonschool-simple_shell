#include "shell.h"
#include <stddef.h>  /* For NULL */
#include <stdlib.h>  /* For free */

int main(void) {
    char *command = NULL;

    /* Call prompt function to display prompt */
    prompt();

    /* Call read_input to capture user input */
    command = read_input();

    /* Call execute_command to process the command */
    execute_command(command);

    /* Free dynamically allocated memory */
    free(command);

    return 0;
}

