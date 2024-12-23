#include <stdio.h>  // For perror and printf
#include <stdlib.h> // For malloc, free, exit
#include "shell.h"  // Include your shell.h header

int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    /* Display the prompt */
    prompt();

    /* Read user input */
    nread = read_input(&command, &len);

    /* Check for errors in reading input */
    if (nread == -1)
    {
        perror("read_input failed");
        free(command);  // Free the memory
        exit(1);         // Exit the program
    }

    /* Execute the command */
    execute_command(command);

    /* Free memory */
    free(command);
    return 0;
}

