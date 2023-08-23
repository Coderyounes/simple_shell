#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

int _strcmp(const char *s1, const char *s2);
int is_piped(void);
void handle_builtins(char *command);
char *readLine();
void exit_builtin(void);
void env_builtin(char *env[]);
void execute_external_command(char *args[], char *env[]);
void tokenizeCommand(char *command, char *args[], int *argc);
void executeCommand(char *args[], char *env[]);
int commandExists(char *command);

#endif
