#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **_strtok(char *str, char *delim)
{
	char *token;
	size_t i = 0, len = 0;
	char **tokenArr = malloc((sizeof(char *) * len) + 1);

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;

	token = strtok(str, delim);
	while (token)
	{
		tokenArr[i] = malloc(sizeof(char) * strlen(token));
		strcpy(tokenArr[i], token);
		i++;
		token = strtok(NULL, delim);
	}

	tokenArr[i] = NULL;

	return (tokenArr);
}
