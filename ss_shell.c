#include "shell.h"

/**
 * prompt - print prompt to screen
 *
 * Return: Nothing
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

int main(int argc, char *argv[], char **env)
{
	char *buf = NULL, **tokens = NULL, **path = NULL;
	size_t n = 0;
	ssize_t no_bytes;
	pid_t pid, wait_status;
	int status;

	(void) argc;
	(void) no_bytes;
	/* array of strings holding the paths in PATH environment variable */
	path = getPath(env);
	while (1)
	{
		size_t i = 0;
		prompt();
		no_bytes = getline(&buf, &n, stdin);
		tokens = _strtok(buf, " \n");

		while (path[i] != NULL)
		{
			/* create absolute path here (e.g. /bin/ls or /usr/bin/ls ...etc) */
			char *absolute_path = strcat(path[i], tokens[0]); /* use _strcat */
			i++;
		/* checks if executable exists (should work for commands in the form "ls" or "/bin/ls" */
		if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
		{
			/* forking begins from here if executable exists */
			pid = fork();

			if (pid < 0)
			{
				size_t j = 0;

				perror("Error: ");

				while (tokens[j] != NULL)
				{
					free(tokens[j]);
					j++;
				}
				free(tokens);
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				size_t j = 0;
				exec_cmd(tokens, argv[0], env);

				while (tokens[j] != NULL)
				{
					free(tokens[j]);
					j++;
				}
				free(tokens);
				/* FREE path */
			}
			else
			{
				size_t j = 0;

				wait_status = waitpid(pid, &status, 0);
				if (wait_status == -1)
				{
					size_t j = 0;

					while (tokens[j] != NULL)
					{
						free(tokens[j]);
						j++;
					}
					free(tokens);
					exit(EXIT_FAILURE);	
				}

				while (tokens[j] != NULL)
				{
					free(tokens[j]);
					j++;
				}
				free(tokens);
				/* FREE path */
			}
			break;
		}
		} /* end while for path */

/**		pid = fork();

		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
//			int exec_val = execve(tokens[0], tokens, NULL);
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(NULL) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}*/
	}
}
