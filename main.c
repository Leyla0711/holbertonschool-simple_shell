#include <stddef.h>  /* Define NULL */
#include "shell.h"

int main(void) {
    char *command = NULL;

    /* Main loop for shell */
    while (1) {
        prompt();  /* Function to display prompt */
        
        command = read_input();  /* Function to read user input */
        
        if (command == NULL) {
            break;  /* Exit if no command is provided */
        }
        
        execute_command(command);  /* Function to execute the command */
    }

    return 0;
}

