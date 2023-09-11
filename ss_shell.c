#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "_putchar.c"
#include "_strtok.c"

int main(int argc, char *argv[])
{
	char *buf = NULL;
//	char *env[] = {NULL};
	char **tokens;
	size_t n = 0;
	ssize_t no_bytes;

	_putchar('$');
	_putchar(' ');
	no_bytes = getline(&buf, &n, stdin);
	printf("%ld\n", no_bytes);
	size_t i = 0;

	tokens = _strtok(buf, " ");

	while (tokens[i])
	{
	//	argv[i] = tokens[i];
		printf("%s", tokens[i]);
		i++;
	}
	printf("%s", tokens[0]);
	execve(tokens[0], tokens, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}
