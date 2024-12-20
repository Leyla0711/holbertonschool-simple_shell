#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>  /* For waitpid */

/* Declare environ globally */
extern char **environ;

/* Function prototypes */
int checkSpecifier(const char *format, int i, va_list arglist);
int _printf(const char *format, ...);
void run_shell(char *command);

#endif /* MAIN_H */
