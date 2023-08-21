#include "main.h"

/**
 * execute_external_command - cmd executer
 *@args: given args
 *@env: env var
 * Return: void
 */
void execute_external_command(char *args[], char *env[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		executeCommand(args, env);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Command executed\n");
		}
	}
}

/**
 * main - mini shell
 * Return: void
 */
int main(void)
{
	char *command;
	char prompt[] = "YOUNESSHELL $> ";
	char *args[MAX_COMMAND_LENGTH / 2];
	int argc;

	while (1)
	{
		printf("%s", prompt);

		command = readLine();

		if (!command)
		{
			printf("\n");
			break;
		}
		tokenizeCommand(command, args, &argc);

		if (argc > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit_builtin();
			}
			else if (strcmp(args[0], "env") == 0)
			{
				env_builtin(environ);
			}
			else if (commandExists(args[0]))
			{
				execute_external_command(args, environ);
			}
			else
			{
				fprintf(stderr, "Command not found: %s\n", args[0]);
			}
		}
		free(command);
	}
	return (0);
}
