/* simple_shell.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Only call the function execute_command from shell.c */
int main(void)
{
    char *command = NULL;

    prompt();  /* Display prompt */
    command = read_input();  /* Get user input */
    execute_command(command);  /* Execute command */
    free(command);

    return (0);
}

