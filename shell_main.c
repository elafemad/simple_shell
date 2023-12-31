#include "shell.h"
/**
 * main - Entry point
 * @ac: The number of command line arguments
 * @argv: The command line arguments
 * Return: Always 0 (Success)
 */
int main(int ac, char **argv);
int main(int ac, char **argv)
{
	char *input = NULL, **command = NULL;
	int status = 0;
	(void)ac;
	(void)argv;

	while (1)
	{
		input = read_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = str_split(input);
		if (!command)
			continue;
		if (_strcmp(command[0], "exit") == 0)
		{
			exit_execute(command, &status);
		}
		else if (_strcmp(command[0], "env") == 0)
		{
			free_str(command);
			env_execute();
			status = 0;
			continue;
		}
		else if (_strcmp(command[0], "setenv") == 0)
		{
			setenv_execute(command);
			status = 0;
			free_str(command);
			continue;
		}
		else if (_strcmp(command[0], "unsetenv") == 0)
		{
			unsetenv_execute(command);
			status = 0;
			free_str(command);
			continue;
		}
		else if (_strcmp(command[0], "cd") == 0)
		{
			cd_execute(command);
			status = 0;
			free_str(command);
			continue;
		}
		cmd_zero_updt(command);
		status = execute_command(command, argv);
	}
}
