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
	char *buf = NULL, **tokens = NULL, *absolute_path = NULL, **path = NULL;
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

		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(buf);
			exit_shell(tokens);
		}

		while (path[i] != NULL)
		{
			absolute_path = get_full_cmd(path[i], tokens[0]);

/*			 create absolute path here (e.g. /bin/ls or /usr/bin/ls ...etc) */

			/*char *absolute_path = malloc(_strlen(path[i]) + _strlen(tokens[0]) + 2);*/
			/* check if allocation succeeds */
/*			_strcpy(absolute_path, path[i]);
			_strcat(absolute_path, tokens[0]);
			 printf("%s\n", absolute_path); */

/*			free_memory(path); FREE path */
			/* checks if executable exists (should work for commands in the form "ls" or "/bin/ls" */
			if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
			{
/*				free(absolute_path);
				printf("got access to executables\n");*/
				/* forking begins from here if executable exists */
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
					exec_cmd(tokens, absolute_path, argv[0], env);
					/* free_memory(tokens); */
					/* free_memory(path);*/ /* FREE path */
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
			/*		free_memory(tokens); */
				}
				break;
			}
			free(absolute_path);
			i++;
		} /* end while for path */
		/* error message for commands not found */
		if (path[i] == NULL)
		{
			write(STDOUT_FILENO, argv[0], strlen(argv[0]));
			write(STDOUT_FILENO, "\n", 1);
		}
	} /* end while for while (1) */
	
	exit(EXIT_SUCCESS);
}
