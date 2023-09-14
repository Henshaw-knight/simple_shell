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
		i++;
		if (strcmp(var, "PATH") == 0)
		{
			val = strtok(NULL, "\n");
			dir = _strtok(val, ":");
			return (dir);
		}
		var = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * exec_cmd - executes the command (first string in tokens)
 * tokens: array of strings that stores the commands
 * shell: name of the shell
 * absolute_path: the full path of command executable
 * env: the environment variables of the process
 *
 * Return: Nothing.
 */

void exec_cmd(char **tokens, char *absolute_path, char *shell, char **env)
{
/*	char **path = NULL;
	size_t i = 0;*/
	struct stat file_status;

	if (stat(tokens[0], &file_status) == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			free_memory(tokens);
			perror(shell);

			exit(EXIT_FAILURE);
		}
	}
	else if (stat(absolute_path, &file_status) == 0)
	{
/*		char *absolute_path = NULL;
		path = getPath(env);

		while (path[i] != NULL)
		{
			absolute_path = malloc(strlen(path[i]) + strlen(tokens[0]) + 2);
			 check if allocation succeeds */
/*			strcpy(absolute_path, path[i]);
			strcat(absolute_path, "/");
			strcat(absolute_path, tokens[0]);
			absolute_path[strlen(absolute_path) + 1] = '\0';

			if (stat(absolute_path, &file_status) == 0)
			{
				printf("%s-%ld\n", absolute_path, strlen(absolute_path));  remove later */
		if (execve(absolute_path, tokens, env) == -1)
		{
/*			free_memory(path);*/
			free_memory(tokens);
			free(absolute_path);
			perror(shell);

			exit(EXIT_FAILURE);
		}
/*			}
			free(absolute_path);
			i++;
		}*/
	}
	/* command does not exist. Print error message and free memory */
/*	free_memory(path);*/
	/* print error message */
}
