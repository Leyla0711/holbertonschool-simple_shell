#include <fcntl.h>   /* For open and O_RDONLY */
#include <unistd.h>  /* For close */

/**
 * exist - Check if a file exists
 * @pathname: The file path
 * Return: 1 if the file exists, 0 otherwise
 */
int exist(const char *pathname)
{
    int exist_stat;

    exist_stat = open(pathname, O_RDONLY); /* Open the file in read-only mode */
    if (exist_stat == -1)
        return 0; /* File does not exist */

    close(exist_stat); /* Close the file descriptor */
    return 1; /* File exists */
}

