/**
 * _strncmp - compares two strings up to n bytes
 * @s1: the first string
 * @s2: the second string
 * @n: number of bytes to compare
 *
 * Return: 0 if both strings are equal, n or -n otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	int diff = 0, index = 0;

	while ((s1[index] != '\0' && s2[index] != '\0') && index < n)
	{
		diff = s1[index] - s2[index];
		if (diff != 0)
			break;
		index++;
	}
	return (diff);
}
