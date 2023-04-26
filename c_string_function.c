#include "shell.h"

/**
 * _itoa - Convert int to char
 * @n: Int to convert
 * Return: char pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, x = 0;
	char *str;

	len = int_len(n);
	str = malloc(len + 1);

	if (str == NULL)
	{
		return (NULL);
	}
	*str = '\0';
	while (n / 10)
	{
		str[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}
	str[x] = (n % 10) + '0';
	rev_array(str, len);
	str[x + 1] = '\0';
	return (str);
}

/**
 * _puts - print a string
 * @str: char pointer
 * return: void
 */
void _puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}

/**
 * string_copy - Copy string
 * @dest: Destination
 * @src: Source
 * Return: char pointer
 */
char *string_copy(char *dest, char *src)
{
	int x = 0;

	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/**
 * string_concat - Concatenate 2 strings
 * @dest: String destination
 * @src: String source
 * Return: string pointer
 */
char *string_concat(char *dest, char *src)
{
	char *str = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (str);
}
/**
 * char_locator - Character locator
 * @str: String search from
 * @ch: Char to search For
 * Return: Pointer to char
 */
char *char_locator(char *str, char ch)
{
	do {
		if (*str == ch)
		{
			break;
		}
	} while (*str++);
	return (str);
}
