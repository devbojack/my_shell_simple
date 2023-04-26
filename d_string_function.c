#include "shell.h"

/**
 * string_compare - Compare character amount of strings
 * @str1: String 1
 * @str2: String 2
 * @size: Character amount
 * Return: 1 or 0
 */
int string_compare(const char *str1, const char *str2, size_t size)
{
	size_t x;

	if (str1 == NULL)
	{
		return (-1);
	}
	for (x = 0; x < size && str2[x]; x++)
	{
		if (str1[x] != str2[x])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * str_dup - Duplicate string
 * @str: String to duplicate
 * Return: string or NULL
 */
char *str_dup(char *str)
{
	size_t len, x;
	char *dupd;

	len = str_len(str);
	dupd = malloc(sizeof(char) * (len + 1));
	if (dupd == NULL)
	{
		return (NULL);
	}

	for (x = 0; x <= len; x++)
	{
		dupd[x] = str[x];
	}

	return (dupd);
}
