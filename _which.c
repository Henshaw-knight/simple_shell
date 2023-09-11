#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	size_t i = 1;
	struct stat sf;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	while (argv[i])
	{
		if (stat(argv[i], &sf) == 0)
		{
			printf("%s FOUND\n", argv[i]);	
		}
		else
		{
			printf("%s NOT FOUND\n", argv[i]);
			return (-1);
		}
		i++;
	}
}
