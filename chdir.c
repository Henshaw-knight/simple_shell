#include "shell.h"

/**
 * change_dir - change the directory
 * @path: the path to change to
 *
 * Return: 0 on success, errno value on failure
 */

int change_dir(char *path)
{
	char *cwd = NULL;
	char *oldpwd = NULL;
	size_t size = 0;

	if (path == NULL)
		path = getcwd(cwd, size);

	if (_strcmp(path, "-") == 0)
	{
		oldpwd = _getenv("OLDPWD");
		if (chdir(oldpwd) != 0)
		{
			perror(oldpwd);
			return (errno);
		}
	}
	else if (chdir(path) == -1)
	{
		perror(path);
		return (errno);
	}
	free(cwd);
	return (0);
}
