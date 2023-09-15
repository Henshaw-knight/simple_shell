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

	(void) argc;
	/* (void) no_bytes; */
	/* array of strings holding the paths in PATH environment variable */
	path = getPath(env);
	while (1)
	{
		size_t i = 0;
		prompt();
		no_bytes = getline(&buf, &n, stdin);
		
		if (no_bytes == EOF)
			_EOF(buf);	
		if (_strcmp(buf, "\n") == 0)
			free(buf);

		tokens = _strtok(buf, " \n");

		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(buf);
			exit_shell(tokens);
		}
		else if (_strcmp(tokens[0], "cd") == 0)
			change_dir(tokens[1]);
		else if (_strcmp(tokens[0], "env") == 0)
	/*		execve(tokens[0], tokens, env);*/
			print_env(env);
		else
		{
		while (path[i] != NULL)
		{
/*			 create absolute path here (e.g. /bin/ls or /usr/bin/ls ...etc) */
			absolute_path = get_full_cmd(path[i], tokens[0]);
			
			/* checks if executable exists (should work for commands in the form "ls" or "/bin/ls" */
			if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
			{
				/* forking begins from here if executable exists */
				child_process(tokens, absolute_path, argv[0], env);
				
				break;
			}
			free(absolute_path);
			i++;
		}	/* end while for path */
		}
		/* error message for commands not found */
		if (path[i] == NULL)
		{
			write(STDOUT_FILENO, argv[0], strlen(argv[0]));
			write(STDOUT_FILENO, "\n", 1);
		}
		if (no_bytes == -1)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
	} /* end while for while (1) */
	
	exit(EXIT_SUCCESS);
}
