#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "_putchar.c"
#include "_strtok.c"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	char *buf = NULL;
	/* char *env[] = {NULL}; */
	char **tokens;
	size_t n = 0;
	ssize_t no_bytes;
	pid_t pid;

	while (1)
	{
		size_t i = 0;
		_putchar('$');
		_putchar(' ');
		no_bytes = getline(&buf, &n, stdin);
		printf("%ld\n", no_bytes);
		/* buf[strlen(buf) - 1] = '\0'; */
		tokens = _strtok(buf, " \n");

		while (tokens[i])
		{
			/* argv[i] = tokens[i]; */
			i++;
		}

		pid = fork();

		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			int exec_val = execve(tokens[0], tokens, NULL);
			if (exec_val == -1)
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
		}
	}
	return (0);
}
