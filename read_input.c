#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

ssize_t read_input(char **command, size_t *len)
{
    /* Read the user input using getline */
    return getline(command, len, stdin); /* getline returns ssize_t */
}

