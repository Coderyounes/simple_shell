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
 * @input: input
 * Return: call to function
 */
void handle_builtins(char *commands, char *input)
{
	if (_strcmp(commands[0], "exit") == 0)
	{
		printf(commands[1]);
		free(input);
		exit_builtin();
	}
	else if (_strcmp(commands[0], "env") == 0)
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
	char *args[MAX_COMMAND_LENGTH / 2];
	char *input;
	size_t input_length;

	while (1)
	{
		printf("%s", "");
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
			handle_builtins(args, input);
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
