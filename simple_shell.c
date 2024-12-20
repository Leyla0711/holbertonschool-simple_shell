#include "main.h"
#include <unistd.h>  /* For execve */
#include <sys/wait.h>  /* For waitpid */
#include <stdlib.h>  /* For malloc */

/* Declare environ globally */
extern char **environ;

/**
 * run_shell - Function to run the shell
 * @command: The command to execute
 */
void run_shell(char *command)
{
    pid_t pid;
    int status;
    char *args[2];  /* Array to hold command and its arguments */

    /* Allocate memory for args dynamically */
    args[0] = command;
    args[1] = NULL;

    pid = fork();
    if (pid == 0) /* Child process */
    {
        if (execve(command, args, environ) == -1) /* Execute command */
        {
            perror("Error executing command");
            exit(1);
        }
    }
    else if (pid < 0) /* Fork failed */
    {
        perror("Fork failed");
        exit(1);
    }
    else /* Parent process */
    {
        waitpid(pid, &status, 0); /* Wait for child process to terminate */
    }
}

