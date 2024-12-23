#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

void prompt(void) {
    /* Display the shell prompt */
    printf("$ ");
}

char *read_input(void) {
    char *input = NULL;
    size_t len = 0;
    
    /* Read user input */
    getline(&input, &len, stdin);

    return input;
}

