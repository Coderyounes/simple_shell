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
	}
}

/**
 * handle_builtins - function to handle built-in case
 * @command: command to check
 * Return: call to function
 */


void handle_builtins(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit_builtin();
	}
	else if (strcmp(command, "env") == 0)
	{
		env_builtin(environ);
	}
}
/**
 * main - mini shell
 * @argc: number of argument
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	char *command;
	char prompt[] = "YOUNESSHELL $> ";
	char input[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH / 2];
	int is_piped = !isatty(STDIN_FILENO);

	argc = 0;
	while (1)
	{
		if (!is_piped)
		{
			printf("%s", prompt);
		}
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';
		command = input;

		tokenizeCommand(command, args, &argc);

		if (argc > 0)
		{
			handle_builtins(args[0]);
			if (commandExists(args[0]))
			{
				execute_external_command(args, environ);
			}
			else
			{
				fprintf(stderr, "%s: %s: command not found\n", argv[0], args[0]);
			}
		}
	}

	return (0);
}
