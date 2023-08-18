#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitter - splits an str
 * @str: str o split
 * Return: list of the elems in str
 */
char **splitter(char *str)
{
	char *DELIMETER = " \t\n";
	char *token, **tokens = NULL;
	int i = 0;

	token = strtok(str, DELIMETER);

	while (token != NULL)
	{
		i++;
		tokens = realloc(tokens, 2 * i * sizeof(char *));

		if (!tokens)
		{
			perror("realloc problem");
			exit(EXIT_FAILURE);
		}

		tokens[i - 1] = token;
		token = strtok(NULL, DELIMETER);
	}

	return (tokens);
}
