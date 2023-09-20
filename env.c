#include "shell.h"

/**
 * print_env - print environment variables and values
 * @env: array of strings storing environment variables
 *
 * Return: Nothing.
 */

void print_env()
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i])); /* use _strlen() */
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/*void main(void)
{
	print_env();
}*/
