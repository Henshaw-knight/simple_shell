#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: the string concerned
 *
 * Return: the length/count of the string
 */
int _strlen(char *s)
{
	int length = 0;

	for (; s[length] != '\0';)
		length++;

	return (length);
}


/**
 * _strcpy - function that copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest
 *
 * @dest: the destination
 * @src: the source
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}


/**
 * _strcat - function that concatenates two strings
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int length = 0;

	while (dest[length] != '\0')
		length++;
	dest[length] = '/';
	length++;

	for (i = 0; src[i] != '\0'; i++)
		dest[length + i] = src[i];
	dest[length + i] = '\0';

	return (dest);
}

/**
 * _strcmp - function that compares two strings
 *
 * @s1: the first string
 * @s2: the seond string
 *
 * Return: 0, if s1 and s2 are equal, a -ve value if s1 < s2
 * or +ve value if s1 > s2
 */
int _strcmp(const char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
