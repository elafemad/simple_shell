#include "shell.h"
/**
 * _fgetc - Reads a character from the given file stream
 * @m: A pointer to the FILE.
 * Return: integer.
 */
int _fgetc(FILE *m)
{
	unsigned char chr;
	ssize_t b_read = read(fileno(m), &chr, 1);

	if (b_read == 1)
		return (chr);
	else
		return (EOF);
}
/**
 * _getline - read a line from stdin
 * @ptr_buf: pointer to pointer.
 * @size_buf: size.
 * @m: file.
 * Return:integer.
 */
int _getline(char **ptr_buf, size_t *size_buf, FILE *m)
{
	size_t i = 0;
	int idx_buf;

	if (ptr_buf == NULL || size_buf == NULL || m == NULL)
		return (-1);
	if (*ptr_buf == NULL)
	{
		*size_buf = BUFFER_SIZE;
		*ptr_buf = malloc(*size_buf);
		if (*ptr_buf == NULL)
		{
			return (-1);
		}
	}
	while ((idx_buf = _fgetc(m)) != EOF)
	{
		if (idx_buf == '\n')
			break;
		(*ptr_buf)[i++] = idx_buf;
		if (i == *size_buf)
		{
			*size_buf *= 2;
			*ptr_buf = realloc(*ptr_buf, *size_buf);
			if (*ptr_buf == NULL)
				return (-1);
		}
	}
	if (idx_buf == EOF)
		return (-1);
	(*ptr_buf)[i] = '\0';
	return (i);
}
