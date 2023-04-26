#include "shell.h"

/**
 * parse_command - Parse input
 * @input: User input
 * Return: Char array
 */
char **parse_command(char *input)
{
	int i, buffsize = BUFFERSIZE;
	char **tokens;
	char *token;

	if (input == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * buffsize);
	if (tokens == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	token = string_tok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = string_tok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
