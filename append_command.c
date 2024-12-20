#include "main.h"
#include <stdlib.h>  /* For malloc */

/**
 * append_command - Function to append command
 * @dir_path: The directory path
 * @command: The command
 * Return: The full command path
 */
char *append_command(char *dir_path, char *command)
{
    char *command_path;
    int len1, len2;

    len1 = strlen(dir_path);
    len2 = strlen(command);
    
    command_path = malloc(len1 + len2 + 2); /* +1 for '/' and +1 for '\0' */
    if (!command_path)
        return NULL;
    
    strcpy(command_path, dir_path);
    strcat(command_path, "/");
    strcat(command_path, command);

    return command_path;
}

