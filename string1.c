#include "shell.h"
/**
 * _strchr - compute the length of string
 * @str: the input string
 * @a: integer.
 * Return: char.
 */
char *_strchr(const char *str, int a)
{
	while (*str != '\0')
	{
		if (*str == (char)a)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == (char)a)
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 * _strspn - compute the length
 * @str: the input string
 * @acc: pointer.
 * Return: size_t.
 */
size_t _strspn(const char *str, const char *acc)
{
	size_t c = 0;

	while (*str != '\0' && _strchr(acc, *str) != NULL)
	{
		c++;
		str++;
	}
	return (c);
}
/**
 * _strpbrk - Locate the first occurrence
 * @str: the input string
 * @z: pointer.
 * Return: char.
 */
char *_strpbrk(const char *str, const char *z)
{
	while (*str != '\0')
	{
		if (_strchr(z, *str) != NULL)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
/**
 * _strtok - Extracts tokens from a string.
 * @str: The string to be tokenized.
 * @d: The delimiter .
 * Return: char.
 */
char *_strtok(char *str, const char *d)
{
	static char *lt;
	char *start_t;

	if (str == NULL)
	{
		str = lt;
	}
	str += _strspn(str, d);
	if (*str == '\0')
	{
		lt = NULL;
		return (NULL);
	}
	start_t = str;
	str = _strpbrk(start_t, d);
	if (str != NULL)
	{
		*str = '\0';
		lt = str + 1;
	}
	else
	{
		lt = _strchr(start_t, '\0');
	}
	return (start_t);
}
/**
 * _strlen - compute the length of string
 * @str: string
 * Return: len
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}
