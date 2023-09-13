#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;

char *_getenv(const char *name)
{
	char *env_var, *env_val;
	int i = 0;
	while (environ[i])
	{
		env_var = strtok(environ[i], "=");
		if (strcmp(env_var, name) == 0)
		{
			env_val = strtok(NULL, "");
			printf("%s\n", env_val);
		}
		i++;
	}
	return ("SUCCESS");
}
/**
int main(void)
{
	_getenv("LC_ALL");
	return (0);
}
*/
