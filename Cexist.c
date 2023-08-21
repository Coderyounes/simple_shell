#include "main.h"

/**
 * commandExists - cmd checker
 *@command: given cmd
 * Return: 1 or 0
 */
int commandExists(char *command)
{

	char *path_env;
	char *path_env_copy;
	char *path;
	char executable_path[MAX_COMMAND_LENGTH];

	if (access(command, X_OK) == 0)
	{
		printf("Full path found: %s\n", command);
		return (1);
	}

	path_env = getenv("PATH");
	path_env_copy = strdup(path_env);
	path = strtok(path_env_copy, ":");

	while (path != NULL)
	{

		if (strchr(command, '/') != NULL)
		{
			snprintf(executable_path, sizeof(executable_path), "%s", command);
		}
		else
		{
			snprintf(executable_path, sizeof(executable_path), "%s/%s", path, command);
		}

		if (access(executable_path, X_OK) == 0)
		{
			free(path_env_copy);
			return (1);
		}

		path = strtok(NULL, ":");
	}

	free(path_env_copy);
	return (0);
}
