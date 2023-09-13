#include "shell.h"

/**
 * print_env - print environment variables and values
 * env: array of strings storing environment variables
 *
 * Return: Nothing.
 */

void print_env(char **env)
{
	size_t i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i])); //use _strlen()
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
