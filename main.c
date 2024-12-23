#include "shell.h"

int main(void)
{
    char *command = NULL;

    while (1)
    {
        prompt(); /* Display the prompt */
        command = read_input(); /* Read the input command */
        if (command == NULL)
        {
            /* Handle error or exit */
            perror("read_input failed");
            exit(1);
        }

        execute_command(command); /* Execute the command */
        free(command); /* Free memory allocated for the command */
    }

    return 0;
}

