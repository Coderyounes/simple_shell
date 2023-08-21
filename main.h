#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

char *readLine();
void exit_builtin();
void env_builtin(char *env[]);
void execute_external_command(char *args[], char *env[]);
void tokenizeCommand(char *command, char *args[], int *argc);
void executeCommand(char *args[], char *env[]);
int commandExists(char *command);

#endif
