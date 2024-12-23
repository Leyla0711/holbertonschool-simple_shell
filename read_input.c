#include "shell.h"

char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;

    /* Read the input from stdin */
    getline(&line, &len, stdin);
    return line;
}

