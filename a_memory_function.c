#include "shell.h"

/**
 * free_environ - Free Enviroment Variable Array
 * @environ:  Environment variables.
 * Return: Void
 */
void free_environ(char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		free(environ[i]);
	}
}

/**
 * array_filler - Array filler
 * @ptr: pointer
 * @ptrx: int pointer
 * @len: Length int
 * Return: pointer
 */
void *array_filler(void *ptr, int ptrx, unsigned int len)
{
	char *p = ptr;
	unsigned int i = 0;

	while (i < len)
	{
		*p = ptrx;
		p++;
		i++;
	}
	return (ptr);
}

/**
 * re_alloc -  Memory reallocator
 * @ptr: Pointer
 * @old_size: Previous Size
 * @new_size: New Size
 * Return: Void Pointer Rellocated Memory
 */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *rel;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	rel = malloc(new_size);
	if (rel == NULL)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		array_filler(rel, '\0', new_size);
		free(ptr);
	}
	else
	{
		mem_copy(rel, ptr, old_size);
		free(ptr);
	}
	return (rel);

}
