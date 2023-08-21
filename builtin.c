#include "main.h"

/**
 * commandExists - exit
 * Return: void with exit 0
 */
void exit_builtin()
{
	exit(EXIT_SUCCESS);
}

/**
 * env_builtin - print all env variables
 *@env: current env var
 * Return: void
 */
void env_builtin(char *env[])
{
	int i;

	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
}
