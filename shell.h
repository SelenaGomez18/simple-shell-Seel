#ifndef _SHELL_H_
#define _SHELL_H_

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *read_line(void);
char **split_line(char *line);
void free_tokens(char **tokens);
int execute(char **args);
int num_builtins(void);
int shell_cd(char **);
int shell_pwd(char **);
int shell_exit(char **);
void prompt(void);

#endif