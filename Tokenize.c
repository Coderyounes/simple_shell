#include "main.h"

void tokenizeCommand(char *command, char *args[], int *argc) {
    char *token = strtok(command, " ");
    *argc = 0;

    while (token != NULL) {
        args[(*argc)++] = token;
        token = strtok(NULL, " ");
    }
    args[*argc] = NULL;
}
