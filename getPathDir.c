#include "shell.h"

/**
 * getPath - get the paths to the command executables
 * env: the environment variables
 *
 * Return: an array to the paths in PATH variable
 */

char **getPath(char **env)
{
	char **dir = NULL, *var = NULL, *val = NULL;
	size_t i = 0;

	var = strtok(env[i], "=");
	while (env[i] != NULL)
	{
		if (strcmp(var, "PATH") == 0)
		{
			val = strtok(NULL, "\n");
			dir = _strtok(val, ":");
			return (dir);
		}
		i++;
		var = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * exec_cmd - executes the command (first string in tokens)
 * tokens: array of strings that stores the commands
 * shell: name of the shell
 * env: the environment variables of the process
 *
 * Return: Nothing.
 */

void exec_cmd(char **tokens, char *shell, char **env)
{
	char **path = NULL;
	size_t i = 0;
	struct stat file_status;

	if (stat(tokens[0], &file_status) == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			size_t j = 0;

			perror(shell);
			while (tokens[j] != NULL)
			{
				free(tokens[j]);
				j++;
			}
			free(tokens);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		size_t j = 0;
		char *absolute_path = NULL;
		path = getPath(env);

		while (path[i] != NULL)
		{
			absolute_path = strcat(path[i], tokens[0]);
			absolute_path[strlen(absolute_path)] = '\0';// use _strlen
//			absolute_path = strcat(absolute_path, '\0');
			if (stat(absolute_path, &file_status) == 0)
			{
				if (execve(absolute_path, tokens, env) == -1)
				{
					size_t j = 0;

					perror(shell);
					while (path[j] != NULL)
					{
						free(path[j]);
						j++;
					}
					free(path);

					while (tokens[j] != NULL)
					{
						free(tokens[j]);
						j++;
					}
					free(tokens);
					exit(EXIT_FAILURE);
				}
			}
			i++;
		}
		/* command does not exist. Print error message and free memory */
		while (path[j] != NULL)
		{
			free(path[j]);
			j++;
		}
		free(path);
	}
}
