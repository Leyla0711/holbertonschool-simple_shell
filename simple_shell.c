#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For fork, execvp
#include <sys/wait.h>  // For wait

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork(); // Create a new process
    if (pid == 0) {
        /* Child process */
        char *args[] = {command, NULL}; // Prepare the command and args for execvp
        execvp(command, args); // Execute the command
        perror("execvp failed"); // If execvp fails, print error message
        exit(1); // Exit the child process with failure
    } else if (pid > 0) {
        /* Parent process */
        wait(&status); // Wait for child to finish execution
    } else {
        perror("fork failed"); // If fork fails, print error message
    }
}

int main(void) {
    char *command = "ls";  // Example command for testing
    execute_command(command); // Execute the command
    return 0;
}

