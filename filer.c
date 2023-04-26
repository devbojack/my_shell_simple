#include "shell.h"
/**
 * file_reader - Read file command
 * @filename: File name
 * @argv: Program Name
 * Return: -1 or 0
 */
void file_reader(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		file_fixer(line, counter, fp, argv);
	}
	if (line)
	{
		free(line);
	}
	fclose(fp);
	exit(0);
}
/**
 * file_fixer - File fixer
 * @line: file line
 * @counter: counter
 * @fp: File descriptor
 * @argv: Program name
 * Return : void
 */
void file_fixer(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_command(line);

	if (string_compare(cmd[0], "exit", 4) == 0)
	{
		exit_bul_for_file(cmd, line, fp);
	}
	else if (built_in_checker(cmd) == 0)
	{
		st = handle_builtin(cmd, st);
		free(cmd);
	}
	else
	{
		st = cmd_checker(cmd, line, counter, argv);
		free(cmd);
	}
}
/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @line: File line
 * @cmd: Command
 * @fd: File descriptor
 * Return : Exit status
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (is_alphabet(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}

/**
 * built_in_checker - check built-in
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int built_in_checker(char **cmd)
{
	int i = 0;
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}};

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (str_compare(cmd[0], (fun + i)->command) == 0)
		{
			return (0);
		}
		i++;
	}
	return (-1);
}
/**
 * create_environ - Create enviroment array
 * @environ: what to create
 * Return: void
 */
void create_environ(char **environ)
{
	int x;

	for (x = 0; environ[x]; x++)
	{
		environ[x] = str_dup(environ[x]);
	}
	environ[x] = NULL;
}
