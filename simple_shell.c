#include "shell.h"
#include <unistd.h>  /* For fork, execvp */
#include <sys/wait.h> /* For wait */
#include <stdlib.h> /* For malloc, free */

void execute_command(char *command)
{
    pid_t pid = fork(); /* Create a new process */

    if (pid == -1)
    {
        perror("fork failed"); /* Fork failed */
        exit(1);
    }
    else if (pid == 0)
    {
        /* Child process */
        char **args = malloc(2 * sizeof(char *)); /* Allocate memory for args */
        if (args == NULL)
        {
            perror("malloc failed");
            exit(1);
        }

        args[0] = command;  /* The first argument is the command itself */
        args[1] = NULL;     /* The last element should be NULL to indicate end of arguments */

        if (execvp(command, args) == -1)
        {
            perror("execvp failed"); /* Exec failed */
            free(args); /* Free the allocated memory */
            exit(1);
        }
    }
    else
    {
        /* Parent process */
        wait(NULL); /* Wait for the child process to finish */
    }
}

