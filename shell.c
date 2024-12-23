#include "shell.h"

int execute_command(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;  /* No command to execute */
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        /* Child process */
        if (execve(args[0], args, NULL) == -1) {
            perror(args[0]);  /* Print error if execve fails */
        }
        exit(1);
    } else {
        /* Parent process */
        waitpid(pid, &status, 0);
    }

    return 1;  /* Continue execution */
}

