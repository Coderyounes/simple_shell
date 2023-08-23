#include "main.h"

/**
 * is_piped - function to check if the command run via pipe
 *
 * Return: 0 if it Real other wise none
 */

int is_piped(void)
{
	return (isatty(STDIN_FILENO) == 0);
}
