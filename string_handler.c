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
char *_strcpy(char *dest, char *src)
{
	int i, length = 0;
	
	while (src[length] != '\0')
		length++;

	for (i = 0; i < length && src[i] != '\0'; i++)
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
