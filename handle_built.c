#include "shell.h"
/**
 * exit_execute - exit the shell
 * @command: the command
 * @status: the status
 */
void exit_execute(char **command, int *status)
{
	if (command[1] == NULL)
	{
		free_str(command);
		exit(*status);
	}
	*status = atoi(command[1]);
	if (command[1][0] == '-')
	{
		*status = 2;
		print_line("./hsh: 1: exit: Illegal number: ");
		print_line(command[1]);
		print_line("\n");
		free_str(command);
		exit(*status);
	}
	else if (not_num(command[1]))
	{
		*status = 2;
		print_line("./hsh: 1: exit: Illegal number: ");
		print_line(command[1]);
		print_line("\n");
		free_str(command);
		exit(*status);
	}
	free_str(command);
	exit(*status);
}
/**
 * cd_execute - execute the cd command.
 * @command: The command to execute
 * Return: Nothing
 */
void cd_execute(char **command)
{
	char *path = NULL, cwd[PATH_MAX], *home = NULL;

	home = getcwd(cwd, sizeof(cwd));
	if (command[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
			return;
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			print_string(home);
			_putchar('\n');
			return;
		}
		print_string(path);
		_putchar('\n');
	}
	else
	{
		path = command[1];
	}
	if (chdir(path) == -1)
	{
		print_line("./hsh: 1: cd: can't cd to ");
		print_line(path);
		print_char('\n');
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return;
	if (setenv("OLDPWD", getenv("PWD"), 1) == -1)
		return;
	if (setenv("PWD", cwd, 1) == -1)
		return;
}
