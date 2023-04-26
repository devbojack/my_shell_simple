#include "shell.h"

/**
 * freeler - Free Array
 * @input: Pointer to array
 * @line: pointer to char
 * Return: void/nothing
 */
void freeler(char **input, char *line)
{
	free(input);
	free(line);
	input = NULL;
	line = NULL;
}

/**
 * mem_copy - copy memory
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @size: Size (How Much You Will Copy)
 * Return: pointer
 */
char *mem_copy(char *dest, char *src, unsigned int size)
{
	unsigned int x;

	for (x = 0; x < size; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}

/**
 * c_alloc -  Array Memory allocator.
 * @size: Size to allocate
 * Return: null or pointer
 */
void *c_alloc(unsigned int size)
{
	char *ptrx;
	unsigned int x;

	if (size == 0)
	{
		return (NULL);
	}
	ptrx = malloc(size);
	if (ptrx == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < size; x++)
	{
		ptrx[x] = '\0';
	}
	return (ptrx);
}
