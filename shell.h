/* shell.h */
#ifndef SHELL_H
#define SHELL_H

/* Function prototypes */
void prompt(void);
char *read_input(void);
void execute_command(char *command);  /* Declare execute_command once */

#endif /* SHELL_H */

