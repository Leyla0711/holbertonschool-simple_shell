#include <stdio.h>
#include <stdlib.h>

/* Function to handle error messages and exit gracefully */
void handle_error(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

