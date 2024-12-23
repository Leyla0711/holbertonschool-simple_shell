/* read_input.c */
#include "shell.h"
#include <stdlib.h>

ssize_t read_input(char **command, size_t *len)
{
    return getline(command, len, stdin);  /* getline returns ssize_t */
}

