#include "shell.h"
/**
 * execute_command - execute
 * @cmd: a pointer
 * @argv: command line
 * Return: status
 */
int execute_command(char **cmd, char **argv)
{
	int status;
	pid_t pid;

	if (strchr(cmd[0], '/') == NULL)
	{
		print_line(argv[0]);
		print_line(": 1: ");
		print_line(cmd[0]);
		print_line(": not found\n");
		free_str(cmd);
		status = 127;
		return (status);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			print_line(argv[0]);
			print_line(": 1: ");
			print_line(cmd[0]);
			print_line(": not found\n");
			free_str(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_str(cmd);
	}
	return (WEXITSTATUS(status));
}
/**
 * not_num - check if a string cannot be casted to integer
 * @str: string
 * Return: 1 if success, 0 if fail
 */
int not_num(char *str)
{
	int i = 0;

	if (str[0] == '\0')
		return (1);
	if (str[0] == '-')
		i = 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
