#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed command
 * @st: status of last command
 * Return: -1 or 0
 */

int handle_builtin(char **cmd, int st)
{
	int i = 0;
	bul_t bil[] = {
		{"cd", dir_changer},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", display_history},
		{NULL, NULL}
	};

	while ((bil + i)->command)
	{
		if (str_compare(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, st));
		}
		i++;
	}
	return (-1);
}
/**
 * cmd_checker - Do simple shell command
 * @cmd: Parsed command
 * @input: User input
 * @c: Shell command not found
 * @argv: Program name
 * Return: 1 or -1
 */
int cmd_checker(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}
	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (string_compare(*cmd, "./", 2) != 0 && string_compare(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_handler - Handle ^C
 * @sign: signal
 * Return: Void
 */
void signal_handler(int sign)
{
	if (sign == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
