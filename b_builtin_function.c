#include "shell.h"

/**
 * display_help - Displaying Help For Builtin
 * @cmd: Command
 * @er: Last command state
 * Return: 0 or -1
 */
int display_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bul - Execute echo cases
 * @cmd: Parsed command
 * @st: Statue of last comamnd
 * Return: 0
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (string_compare(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (string_compare(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (string_compare(cmd[1], "$PATH", 5) == 0)
	{
		path = get_environ("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}

/**
 * display_history - Display History
 * @c: Parsed command
 * @s: statue of last command
 * Return: 0 or -1
 */
int display_history(__attribute__((unused))char **c,
	__attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);
	}
	if (line)
	{
		free(line);
	}
	fclose(fp);
	return (0);
}

/**
 * print_echo - Execute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 or -1
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
