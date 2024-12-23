#include "shell.h"
#include <stdio.h>  /* For getline */
#include <stdlib.h> /* For free */

char *read_input(void)
{
    size_t len = 0;
    char *input = NULL;

    if (getline(&input, &len, stdin) == -1)
    {
        free(input); /* Free memory in case of failure */
        return NULL;
    }

    return input;
}
 
