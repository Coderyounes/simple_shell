#include "main.h"

void exit_builtin() {
    exit(EXIT_SUCCESS);
}

void env_builtin(char *env[]) {
    int i;

    for (i = 0; env[i]; i++) {
        printf("%s\n", env[i]);
    }
}
