#include "shell.h"

/**
* _getline - Read The Input By User From Stdin
* Return: Input
*/
char *_getline()
{
	int i, buffsize = BUFFERSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = re_alloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	handle_hashtag(buff);
	return (buff);
}

/**
 * handle_hashtag - remove everything
 * @buff: user input
 * Return: void
 */
void handle_hashtag(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}

/**
 * b_exit - Simple shell exit status
 * @cmd: Parsed command
 * @input: User input
 * @argv: Program name
 * @count: Count
 * Return: void
 */
void b_exit(char **cmd, char *input, char **argv, int count)
{
	int status, x = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][x])
	{
		if (is_alphabet(cmd[1][x++]) != 0)
		{
			pr_error(argv, count, cmd);
			break;
		}
		else
		{
			status = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

/**
 * dir_changer - Directory changer
 * @cmd: Parsed Command
 * @state: Status Last Command Excuted
 * Return: 0 or 1
 */
int dir_changer(char **cmd, __attribute__((unused))int state)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		value = chdir(get_environ("HOME"));
	}
	else if (str_compare(cmd[1], "-") == 0)
	{
		value = chdir(get_environ("OLDPWD"));
	}
	else
	{
		value = chdir(cmd[1]);
	}

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", get_environ("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - Show environ var
 * @cmd: Command
 * @er: Last command state
 * Return:Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = str_len(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
