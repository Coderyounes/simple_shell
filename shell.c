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
	if (_strcmp(command, "exit") == 0)
	{
		exit_builtin();
	}
	else if (_strcmp(command, "env") == 0)
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
	char prompt[] = "";
	char *input;
	char *args[MAX_COMMAND_LENGTH / 2];
	size_t input_length;

	argc = 0;
	while (1)
	{
		{
			printf("%s", prompt);
			fflush(stdout);
		}
		input = readLine();
		if (input == NULL)
			break;
		input_length = strlen(input);
		if (input_length > 0 && input[input_length - 1] == '\n')
		{
			input[input_length - 1] = '\0';
		}
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
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
				free(input);
				exit(127);
			}
		}
		free(input);
	}
	return (0);
}
