#include "shell.h"

/**
 * change_dir - change the directory
 * @path: the path to change to
 *
 * Return: 0 on success, errno value on failure
 */

int change_dir(const char *path)
{
	char *cwd = NULL, *path_cpy = NULL;
	size_t size = 0;

	if (path == NULL)
		path = getcwd(cwd, size);
	if (_strcmp(path, "-") == 0)
	{
		_strcpy(path_cpy, path);
		path_cpy = "../";
		chdir(path_cpy);
		return (0);
	}
	if (chdir(path) == -1)
	{
		perror(path);
		return (errno);
	}
	free(cwd);
	free(path_cpy);
	return (0);
}
