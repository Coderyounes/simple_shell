#include "main.h"

char *readLine() {
    char *line = NULL;
    size_t bufferSize = 0;

    ssize_t bytesRead = getline(&line, &bufferSize, stdin);

    if (bytesRead == -1) {
        if (feof(stdin)) {
            free(line);
            return NULL;
        } else {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }
    }

    if (line[bytesRead - 1] == '\n') {
        line[bytesRead - 1] = '\0';
    }

    return line;
}
