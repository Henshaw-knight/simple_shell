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
			char *absolute_path = strcat(path[i], "/"); /* use _strcat */
			absolute_path = strcat(path[i], tokens[0]); /* use _strcat */
			printf("%s\n", absolute_path);
			i++;
		/* checks if executable exists (should work for commands in the form "ls" or "/bin/ls" */
		if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
		{
			printf("got access to executables\n");
			/* forking begins from here if executable exists */
			pid = fork();

			if (pid < 0)
			{
				free_memory(tokens);
				perror("Error: (fork)");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				exec_cmd(tokens, argv[0], env);
				free_memory(tokens);
				/* FREE path */
			}
			else
			{
				wait_status = waitpid(pid, &status, 0);
				if (wait_status == -1)
				{
					free_memory(tokens);
					exit(EXIT_FAILURE);	
				}

				free_memory(tokens);
				/* FREE path */
			}
			break;
		}
		} /* end while for path */
	}
}
