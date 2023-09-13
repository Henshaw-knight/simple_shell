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
	(void) argc;
	char *buf = NULL,  **tokens = NULL;
	/* char *env[] = {NULL}; */
	size_t n = 0;
	ssize_t no_bytes;
	pid_t pid, wait_status;
	int status;

	while (1)
	{
		size_t i = 0;
		prompt();
		no_bytes = getline(&buf, &n, stdin);
		/* buf[strlen(buf) - 1] = '\0'; */
		tokens = _strtok(buf, " \n");

		if (access(tokens[0], X_OK) == 0)
		{
			pid = fork();

			if (pid < 0)
			{
				perror("Error: ");
				size_t j = 0;

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
				exec_cmd(tokens, argv[0], env);
				size_t j = 0;

				while (tokens[j] != NULL)
				{
					free(tokens[j]);
					j++;
				}
				free(tokens);
			}
			else
			{
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
				size_t j = 0;

				while (tokens[j] != NULL)
				{
					free(tokens[j]);
					j++;
				}
				free(tokens);
			}
		}
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
