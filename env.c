#include "shell.h"

/**
 * print_env - print environment variables and values
 *
 * Return: Nothing.
 */

void print_env(void)
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _getenv - Searches the environment variables list to
 * find a specific variable name
 * @name: environment variable
 *
 * Return: pointer to the corresponding/matching string
 */
char *_getenv(char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
			return (&environ[i][_strlen(name) + 1]);
		i++;
	}
	return (NULL);
}
