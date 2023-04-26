#include "shell.h"

/**
 *  pr_error - Print error
 * @argv: Prog name
 * @count: Count for errors
 * @cmd: Command
 * Return: Void
 */
void pr_error(char **argv, int count, char **cmd)
{
	char *er = _itoa(count);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
