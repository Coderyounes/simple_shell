#include "main.h"

/**
 * executeCommand - execute a cmd
 *@args: given args
 *@env: current env
 * Return: void
 */
void executeCommand(char *args[], char *env[])
{
	printf("init execute cmd");
	char *path_env;
	char *path;
	char executable_path[MAX_COMMAND_LENGTH];

	if (access(args[0], X_OK) == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
	}

	path_env = getenv("PATH");

	printf("______________________________________ %s", path_env);
	path = strtok(path_env, ":");
	while (path != NULL)
	{
		snprintf(executable_path, sizeof(executable_path), "%s/%s", path, args[0]);

		if (access(executable_path, X_OK) == 0)
		{
			if (execve(executable_path, args, env) == -1)
			{
				perror("Command execution error");
				exit(EXIT_FAILURE);
			}
		}

		path = strtok(NULL, ":");
	}

	fprintf(stderr, "Command not found\n");
	exit(EXIT_SUCCESS);
}
