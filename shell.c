#include "shell.h"

/**
 * main - Simple shell
 * @argc: Argument count
 * @argv: Argument parameters
 * Return: integer
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int counter = 0, status = 1, st = 0;
	char *input, **command;

	if (argv[1] != NULL)
	{
		file_reader(argv[1], argv);
	}
	signal(SIGINT, signal_handler);
	while (status)
	{
		counter++;
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}
		input = _getline();

		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		command = parse_command(input);
		if (str_compare(command[0], "exit") == 0)
		{
			b_exit(command, input, argv, counter);
		}
		else if (built_in_checker(command) == 0)
		{
			st = handle_builtin(command, st);
			freeler(command, input);
			continue;
		}
		else
		{
			st = cmd_checker(command, input, counter, argv);
		}
		freeler(command, input);
	}
	return (status);
}
