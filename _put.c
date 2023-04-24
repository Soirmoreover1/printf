#include "main.h"

/**
 * _putchar - write char c
 * @c: to print character
 * Return: On success 1 || -1
 */

int _putchar(int c)
{
	static int index;
	static char buffer[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || index >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (c != BUF_FLUSH)
		buffer[index++] = c;
	return (1);
}

/**
 * _puts - print string with a newline
 * @str: input string
 * Return: bytes number
 */

int _puts(char *str)
{
	char *start = str;

	while (*str)
		_putchar(*str++);
	return (str - start);
}

