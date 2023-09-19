#include "shell.h"

/**
 * child_process - forks a process
 * @tokens: array of strings storing the commands
 * @absolute_path: the absolute path of command executable
 * @shell: name of the program
 * @env: environment variables of the process
 *
 * Return: Nothing.
 */

void child_process(char **tokens, char *absolute_path, char *shell, char **env)
{
	pid_t pid, wait_status;
	int status;

	if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
	{
		pid = fork();

		if (pid < 0)
		{
			free_memory(tokens);
			free(absolute_path);
			perror("Error: (fork)");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			exec_cmd(tokens, absolute_path, shell, env);
			free(absolute_path);
			free_memory(tokens);
		}
		else
		{
			wait_status = waitpid(pid, &status, 0);
			if (wait_status == -1)
			{
				free_memory(tokens);
				free(absolute_path);
				exit(EXIT_FAILURE);
			}
			free(absolute_path);
			free_memory(tokens);
		}
	}
}
