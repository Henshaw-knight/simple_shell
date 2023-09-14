#include "shell.h"

/**
 * free_memory - function that frees allocated memory
 *
 * @buf: The pointer allocated memory that will be freed
 *
 * Return: void (Nothing)
 */
void free_memory(char **buffer)
{
	size_t j = 0;

	if (buffer == NULL)
		return;

	while (buffer[j] != NULL)
	{
		free(buffer[j]);
		j++;
	}

/*	if (buffer[j] == NULL)
		free(buffer[j]);*/
	free(buffer);
}
