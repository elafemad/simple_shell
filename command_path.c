#include "shell.h"
/**
 * command_path - get command path.
 * @cmd: command.
 * Return: 0
 */

char *command_path(char *cmd)
{
	char *f_pth = NULL;
	char *env_pth = _getenv("PATH");
	char *cpy_pth;
	char *token;
	char buf[1024];

	if (strchr(cmd, '/') != NULL)
	{
		f_pth = _strdup(cmd);
		return (f_pth);
	}
	if (env_pth == NULL)
	{
		return (NULL);
	}
	cpy_pth = _strdup(env_pth);
	token = _strtok(cpy_pth, ":");
	while (token != NULL)
	{
		_strcpy(buf, token);
		_strcat(buf, "/");
		_strcat(buf, cmd);
		if (access(buf, X_OK) == 0)
		{
			f_pth = _strdup(buf);
			break;
		}
		token = _strtok(NULL, ":");
	}
	free(cpy_pth);
	return (f_pth);
}
/**
 * cmd_zero_updt - get full path .
 * @cmd: pointer to pointer.
 * Return: void.
 */
void cmd_zero_updt(char **cmd)
{
	size_t new_len;
	char *new_str = command_path(cmd[0]);

	if (new_str == NULL)
		return;

	free(cmd[0]);
	new_len = _strlen(new_str);
	cmd[0] = malloc((new_len + 1) * sizeof(char));

	_strcpy(cmd[0], new_str);

	free(new_str);
}
