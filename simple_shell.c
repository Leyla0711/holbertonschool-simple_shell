#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define PROMPT "#cisfun$ "

/* Extern declaration for the environment variable */
extern char **environ;

/**
 * main - Simple Shell main function
 *
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        /* Display prompt */
        printf(PROMPT);
        fflush(stdout);

        /* Read input from user */
        nread = getline(&line, &len, stdin);

        /* Handle EOF (Ctrl+D) */
        if (nread == -1)
        {
            if (feof(stdin))  /* Check for EOF */
            {
                free(line);
                printf("\n");
                exit(0);
            }
            else
            {
                perror("getline");
                exit(1);
            }
        }

        /* Remove trailing newline character */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        /* Create child process to execute command */
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0) /* Child process */
        {
            /* Execute command using execve */
            if (execve(line, (char *[]) {line, NULL}, environ) == -1)
            {
                /* If execve fails, print error message */
                perror("./shell");
                exit(1);
            }
        }
        else /* Parent process */
        {
            /* Wait for the child process to terminate */
            waitpid(pid, &status, 0);
        }
    }

    /* Free memory and exit */
    free(line);
    return 0;
}
