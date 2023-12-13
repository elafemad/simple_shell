#include "shell.h"
/**
 * _strcat - concatenates two string
 * @destination: destniation
 * @source: source
 * Return: pointer
 */
char *_strcat(char *destination, char *source)
{
	char *p = destination;

	while (*p != '\0')
	{
		p++;
	}
	while (*source != '\0')
	{
		*p = *source;
		p++;
		source++;
	}
	*p = '\0';
	return (destination);
}
/**
 * _strdup - duplicate string
 * @string:  string
 * Return: pointer
 */
char *_strdup(char *string)
{
	size_t length = strlen(string) + 1;
	char *n_string = (char *)malloc(length * sizeof(char));

	if (n_string == NULL)
		exit(EXIT_FAILURE);
	strcpy(n_string, string);
	return (n_string);
}
/**
 * _strcmp - compare two string
 * @string1: first
 * @string2: seconed
 * Return: integer
 */
int _strcmp(char *string1, char *string2)
{
	while (*string1 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
/**
 * _strcpy - copy
 * @destination: destination
 * @source: source
 * Return: pointer
 */
char *_strcpy(char *destination, char *source)
{
	char *p = destination;

	while (*source != '\0')
	{
		*p = *source;
		p++;
		source++;
	}
	*p = '\0';
	return (destination);
}
/**
 * _strncmp - compare
 * @str1: string 1
 * @str2: string 2
 * @n: max_size
 * Return: int
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		if (str1[i] == '\0')
		{
			break;
		}
	}
	return (0);
}
