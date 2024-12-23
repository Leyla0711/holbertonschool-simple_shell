#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    prompt();  // Display the prompt

    // Read the input using getline
    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        perror("getline");
        exit(1);
    }

    // Remove the newline character from the input, if it exists
    line[strcspn(line, "\n")] = 0;

    if (strlen(line) == 0)
    {
        free(line);
        return 0;
    }

    // Execute the command entered by the user
    execute_command(line);

    // Free allocated memory
    free(line);
    return 0;
}

