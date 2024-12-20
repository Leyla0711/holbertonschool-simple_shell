#include "main.h"
#include <unistd.h>
#include <stdlib.h>  /* For exit */

/**
 * exec - Function to execute a command
 * @arguments: Array of arguments for execve
 * Return: The execution status
 */
int exec(char **arguments)
{
    pid_t pid;
    int exe_stat;

    pid = fork();
    if (pid == 0)  /* Child process */
    {
        exe_stat = execve(arguments[0], arguments, environ); /* Execute command */
        if (exe_stat == -1)
        {
            perror("Exec failed");
            exit(1);  /* Terminate the child process with failure status */
        }
    }
    else if (pid < 0)  /* Fork failed */
    {
        perror("Fork failed");
        exit(1);
    }
    return 0;  /* Parent process */
}
