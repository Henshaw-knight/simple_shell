#include <stdio.h>
#include <unistd.h>

/**
 * main - get pid of a process
 *
 * Return: Always 0
 */

int main(void)
{
	pid_t my_pid;
	pid_t my_ppid;

	my_pid = getpid();
	my_ppid = getppid();

	printf("%u\n%u\n", my_pid, my_ppid);

	return (0);
}
