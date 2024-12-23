#include "shell.h"

int main(void)
{
    char *line;
    char *args[] = {NULL};

    /* Shell loop */
    line = read_input();
    if (line == NULL) {
        return 1;
    }

    /* Execute the command */
    execute_command(args);
    return 0;
}

