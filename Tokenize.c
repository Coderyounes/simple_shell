#include "main.h"

/**
 * tokenizeCommand - toknize an str
 *@command: custom str
 *@args: the returned args
 *@argc: num of args
 * Return: void
 */
void tokenizeCommand(char *command, char *args[], int *argc)
{
	char *token = strtok(command, " ");
	*argc = 0;

	while (token != NULL)
	{
		args[(*argc)++] = token;
		token = strtok(NULL, " ");
	}
	args[*argc] = NULL;
}
