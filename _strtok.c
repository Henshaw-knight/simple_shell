#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **_strtok(char *str, char *delim)
{
    char *token;
    char *str2 = malloc(sizeof(char) * strlen(str));
    strcpy(str2, str);
    size_t i = 0, len = 0;

    while (str2[i] != '\0')
    {
        len++;
        i++;
    }
    i = 0;
    char **tokenArr = malloc(sizeof(char) * len);

    token = strtok(str2, delim);
    while (token)
    {
        tokenArr[i] = token;
        i++;
        token = strtok(NULL, delim);
    }

    tokenArr[i] = NULL;

    return (tokenArr);
}

/**
 * int main(void)
{
    char str[] = "I love you";
    char **tokens = _strtok(str, " ");
    int i = 0;

    while (tokens[i])
    {
        printf("%s", tokens[i]);
        i++;
    }	
}
*/
