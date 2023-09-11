#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int count = 0;
    int pid;

    while (count < 5)
    {
	count++;
        pid = fork();

        if (pid == 0)
        {
            char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error: Execve returned\n");
            }
        }
        else
        {
            wait(NULL);
        }
    }
}
