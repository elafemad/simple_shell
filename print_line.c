#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: void.
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}


/**
 * print_string - writes the string str to stdout
 * @str: string
 * Return: void.
 */
void print_string(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}


/**
 * print_char - writes the character c to stderr
 * @c: The character to print
 * Return: void.
 */
void print_char(char c)
{
	write(STDERR_FILENO, &c, 1);
}

/**
 * print_line - writes line  string to stdout
 * @str: string
 * Return: void.
 */
void print_line(char *str)
{
	write(1, str, _strlen(str));
}
