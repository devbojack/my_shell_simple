#include "shell.h"

/**
 * string_tok - String token
 * @str: String
 * @lim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *string_tok(char *str, const char *lim)
{
	static char *a, *b;
	unsigned int i;

	if (str != NULL)
		b = str;

	a = b;
	if (a == NULL)
		return (NULL);

	for (i = 0; a[i] != '\0'; i++)
	{
		if (matcher(a[i], lim) == 0)
			break;
	}
	if (b[i] == '\0' || b[i] == '#')
	{
		b = NULL;
		return (NULL);
	}
	a = b + i;
	b = a;
	for (i = 0; b[i] != '\0'; i++)
	{
		if (matcher(b[i], lim) == 1)
			break;
	}
	if (b[i] == '\0')
		b = NULL;
	else
	{
		b[i] = '\0';
		b = b + i + 1;
		if (*b == '\0')
			b = NULL;
	}
	return (a);
}

/**
 * _putchar - writes character
 * @ch: character to print
 * Return: 1 or -1
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * str_copy - Copy a string
 * @dest: destination
 * @src: source
 * @size: Size
 * Return: copied string
 */
char *str_copy(char *dest, char *src, int size)
{
	int x = 0;

	while (x < size && *(src + x))
	{
		*(dest + x) = *(src + x);
		x++;
	}
	while (x < size)
	{
		*(dest + x) = '\0';
		x++;
	}
	return (dest);
}

/**
 * str_len - String length
 * @ch: char to check
 * Return: String length
 */
int str_len(char *ch)
{
	int i;

	for (i = 0; ch[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _atoi - string converter
 * @str: string
 * Return: converted int
 */
int _atoi(char *str)
{
	int a = 0, b, c = 0, x = 1;

	while ((str[a] < '0' || str[a] > '9') && (str[a] != '\0'))
	{
		if (str[a] == '-')
		{
			x *= -1;
		}
		a++;
	}
	b = a;
	while ((str[b] >= '0') && (str[b] <= '9'))
	{
		c = (c * 10) + x * ((str[b]) - '0');
		b++;
	}
	return (c);
}
