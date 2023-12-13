#include "shell.h"
/**
 * read_input - Read a line of input from stdin
 * Return: A pointer to the input line, or NULL if there was no input
 */
char *read_input()
{
	char *buf = NULL;
	size_t buf_sz = 0;
	int b_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	b_read = _getline(&buf, &buf_sz, stdin);

	if (b_read == -1)
	{
		free(buf);
		return (NULL);
	}

	return (buf);
}



/**
 * str_split - Parses a command line.
 * @line: The command line .
 * Return: a pointer.
 */
char **str_split(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int t_conut = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = _strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		t_conut++;
		token = _strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (t_conut + 1));
	if (!cmd)
	{
		free(line);
		return (NULL);
	}
	token = _strtok(line, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = _strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
