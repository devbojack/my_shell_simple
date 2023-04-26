#include "shell.h"

/**
 * print_number - Prints numbers
 * @n: What to print
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
	{
		print_number(x / 10);
	}
	_putchar(x % 10 + '0');
}
/**
 * print_number_in - Print number in
 * @n: What to print
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
	{
		print_number(x / 10);
	}
	_putchar(x % 10 + '0');
}

/**
 * print_error - Display error
 * @input: User input
 * @counter: Loop counter
 * @argv: Program name
 * Return: void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
