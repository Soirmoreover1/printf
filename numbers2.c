#include "main.h"

/**
 * _isdigit - checks char is digit
 *
 * @c: inpu char
 *
 * Return: 1 if digit || 0
 */

int _isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/**
 * _strlen - returns the len of a string
 *
 * @s: the string whose len to check
 *
 * Return: int len of string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * print_number - prints a num with options
 *
 * @str: the base num as a str
 *
 * @parameter: the para struct
 *
 * Return: chars printed
 */

int print_number(char *str, parameter_t *parameter)
{
	unsigned int i = _strlen(str);
	int neg = (!parameter->unsign && *str == '-');

	if (!parameter->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (parameter->precision != UINT_MAX)
		while (i++ < parameter->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!parameter->minus_flag)
		return (print_number_right_shift(str, parameter));
	else
		return (print_number_left_shift(str, parameter));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @parameter: the parameter struct
 * Return: chars printed
 */

int print_number_right_shift(char *str, parameter_t *parameter)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (parameter->zero_flag && !parameter->minus_flag)
		pad_char = '0';
	neg = neg2 = (!parameter->unsign && *str == '-');
	if (neg && i < parameter->width && pad_char == '0' && !parameter->minus_flag)
		str++;
	else
		neg = 0;
	if ((parameter->plus_flag && !neg2) ||
		(!parameter->plus_flag && parameter->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (parameter->plus_flag && !neg2 && pad_char == '0' && !parameter->unsign)
		n += _putchar('+');
	else if (!parameter->plus_flag && parameter->space_flag && !neg2 &&
			 !parameter->unsign && parameter->zero_flag)
		n += _putchar(' ');
	while (i++ < parameter->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (parameter->plus_flag && !neg2 && pad_char == ' ' && !parameter->unsign)
		n += _putchar('+');
	else if (!parameter->plus_flag && parameter->space_flag && !neg2 &&
			 !parameter->unsign && !parameter->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @parameter: the parameter struct
 * Return: chars printed
 */

int print_number_left_shift(char *str, parameter_t *parameter)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (parameter->zero_flag && !parameter->minus_flag)
		pad_char = '0';
	neg = neg2 = (!parameter->unsign && *str == '-');
	if (neg && i < parameter->width && pad_char == '0' && !parameter->minus_flag)
		str++;
	else
		neg = 0;

	if (parameter->plus_flag && !neg2 && !parameter->unsign)
		n += _putchar('+'), i++;
	else if (parameter->space_flag && !neg2 && !parameter->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < parameter->width)
		n += _putchar(pad_char);
	return (n);
}
