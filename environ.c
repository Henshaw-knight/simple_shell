#include <stdio.h>

extern char **environ;  // Declare extern to access the global environ variable

int main(int argc, char **argv, char **env)
{
	int i = 0;
    
	printf("%p\n", env);
	printf("%p\n", environ);
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return 0;
}
