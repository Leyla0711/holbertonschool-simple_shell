#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function prototypes */
void prompt(void);  /* Display the prompt */
void execute_command(char *command);  /* Function to execute command */

/* Main function */
int main(void) {
    char *command = "ls";  /* Example command */

    prompt();  /* Display the prompt */

    execute_command(command);  /* Execute the command */

    return 0;
}

/* Function to display the prompt */
void prompt(void) {
    write(STDOUT_FILENO, "$ ", 2);  /* Display prompt */
}

