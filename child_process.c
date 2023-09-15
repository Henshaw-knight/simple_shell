#include "shell.h"

void child_process(char **tokens, char *absolute_path, char *shell, char **env)
{
	pid_t pid, wait_status;
	int status;

/*	if (access(tokens[0], X_OK) == 0 || access(absolute_path, X_OK) == 0)
	{*/
	/*	free(absolute_path);
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
			exec_cmd(tokens, absolute_path, shell, env);
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
/*	}*/
}
