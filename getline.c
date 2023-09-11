#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *buf = NULL;
	size_t n = 0;
	ssize_t length;

	printf("$ ");
	length = getline(&buf, &n, stdin);
	printf("%s\n%lu\n", buf, n);
	printf("%li\n", length);

	return (0);
}
