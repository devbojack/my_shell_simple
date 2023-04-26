#include "shell.h"

/**
 * path_cmd -  Find command in $PATH
 * @cmd: command
 * Return: 1 or 0
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = get_environ("PATH");
	value = string_tok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = str_dup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = string_tok(NULL, ":");
	}
	free(path);
	return (1);
}
/**
 * build - Build function
 * @token: Executable command
 * @value: Containing command
 * Return: char or NULL
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = str_len(value) + str_len(token) + 2;
	cmd = malloc(sizeof(char) * len);

	if (cmd == NULL)
	{
		return (NULL);
	}
	memset(cmd, 0, len);

	cmd = string_concat(cmd, value);
	cmd = string_concat(cmd, "/");
	cmd = string_concat(cmd, token);

	return (cmd);
}
/**
 * get_environ - Gets The Value Of Enviroment Variable By Name
 * @name: Environ name
 * Return: char or NULL
 */
char *get_environ(char *name)
{
	size_t size1, size2;
	char *value;
	int i, x, j;

	size1 = str_len(name);

	for (i = 0 ; environ[i]; i++)
	{
		if (string_compare(name, environ[i], size1) == 0)
		{
			size2 = str_len(environ[i]) - size1;
			value = malloc(sizeof(char) * size2);
			if (value == NULL)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}
			j = 0;

			for (x = size1 + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
