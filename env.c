#include "shell.h"
/**
 * _getenv - get environment path of env variable
 * @n: the name of the env variable
 * Return: The path of env variable
 */
char *_getenv(char *n)
{
	size_t length = _strlen(n);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, n, length) == 0 && (*env)[length] == '=')
		{
			return (&(*env)[length + 1]);
		}
	}
	return (NULL);
}
/**
 * env_execute - execute env command
 */
void env_execute(void)
{
	char **env = environ;

	while (*env)
	{
		print_string(*env);
		_putchar('\n');
		env++;
	}
}
/**
 * setenv_execute - set environment variable
 * @cmd: the command
 * Return: void.
 */
void setenv_execute(char **cmd)
{
	if (cmd[1] == NULL || cmd[2] == NULL)
		return;
	if (setenv(cmd[1], cmd[2], 1) != 0)
	{
		print_line("Error setting environment variable\n");
	}
}
/**
 * unsetenv_execute - unset environment variable
 * @cmd: the command
 * Return: void.
 */
void unsetenv_execute(char **cmd)
{
	if (cmd[1] == NULL)
		return;
	if (unsetenv(cmd[1]) != 0)
	{
		print_line("Error unsetting environment variable\n");
	}
}
