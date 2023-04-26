#include "shell.h"

/**
 * matcher - Char match checker
 * @ch: Character To Check
 * @str: String To Check
 * Return: 1 or 0
 */
unsigned int matcher(char ch, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (ch == str[x])
			return (1);
	}
	return (0);
}

/**
 * str_compare - String compare
 * @str1: String 1
 * @str2: String 2
 * Return: 0 or difference
 */
int str_compare(char *str1, char *str2)
{
	int diff = 0, x, len1, len2;

	len1 = str_len(str1);
	len2 = str_len(str2);

	if (str1 == NULL || str2 == NULL)
	{
		return (1);
	}
	if (len1 != len2)
	{
		return (1);
	}
	for (x = 0; str1[x]; x++)
	{
		if (str1[x] != str2[x])
		{
			diff = str1[x] - str2[x];
			break;
		}
		else
		{
			continue;
		}
	}
	return (diff);
}

/**
 * is_alphabet - Check if its alphabet
 * @ch: Character to check
 * Return: 1 or 0
 */
int is_alphabet(int ch)
{
	if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * rev_array - Reverse Array
 * @arr: Array to reverse
 * @len: Array length
 * Return: Void(Reverse Array)
 */
void rev_array(char *arr, int len)
{
	int x;
	char temp;

	for (x = 0; x < (len / 2); x++)
	{
		temp = arr[x];
		arr[x] = arr[(len - 1) - x];
		arr[(len - 1) - x] = temp;
	}
}

/**
 * int_len - Get length of an int
 * @numb: Int to check
 * Return: The numb length
 */
int int_len(int numb)
{
	int len = 0;

	while (numb != 0)
	{
		len++;
		numb /= 10;
	}
	return (len);
}
