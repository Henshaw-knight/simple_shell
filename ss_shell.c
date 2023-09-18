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

/**
 * main - run the shell program
 * @argc: number of arguments passeed to the program
 * @argv: araay of strings holding the arguments passed
 * to program
 * @env: the environment variables of process
 *
 * Return: Nothing
 */

int main(int argc, char *argv[], char **env)
{
	char *buf = NULL, **tokens = NULL, *absolute_path = NULL, **path = NULL;
	size_t n = 0;
	ssize_t no_bytes;

	(void) argc, path = getPath(env);
	while (1)
	{
		size_t i = 0;

		prompt();
		no_bytes = getline(&buf, &n, stdin);
		if (no_bytes == EOF)
			_EOF(buf);
		tokens = _strtok(buf, " \n");
		if (_strcmp(tokens[0], "exit") == 0)
			free(buf), exit_shell(tokens);
		else if (_strcmp(tokens[0], "cd") == 0)
			change_dir(tokens[1]);
		else if (_strcmp(tokens[0], "env") == 0)
			print_env(env);
		else
		{
			do {
				absolute_path = get_full_cmd(path[i], tokens[0]);
				child_process(tokens, absolute_path, argv[0], env), i++;
			} while (path[i] != NULL && absolute_path == NULL);
			error_message(tokens, absolute_path, argv[0]);
		}
		fflush(stdin);
		buf = NULL;
/**		if (no_bytes == -1)
 *		{
 *			free(buf), exit(EXIT_FAILURE);
		}*/
	} /* end while for while (1) */
	exit(EXIT_SUCCESS);
}
