#include "main.h"

/**
 * get_specifier - select suitable print function
 * @s: the format string
 * Return: specifier
 */

int (*get_specifier(char *s))(va_list ap, parameter_t *parameter)
{
	int i = 0;

	specifier_t specifiers[] = {
		{"c", P_char},
		{"d", P_int},
		{"i", P_int},
		{"s", P_string},
		{"%", P_percent},
		{"b", P_binary},
		{"o", P_octal},
		{"u", P_unsigned},
		{"x", P_hex},
		{"X", P_HEX},
		{"p", P_address},
		{"S", print_S},
		{"r", P_reverse},
		{"R", P_rot13},
		{NULL, NULL}};

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @parameter: the parameters struct
 * Return: specifier
 */

int get_print_func(char *s, va_list ap, parameter_t *parameter)
{
	int (*func)(va_list, parameter_t *) = get_specifier(s);

	if (func)
		return (func(ap, parameter));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @parameter: the parameters struct
 * Return: 1 || 0
 */

int get_flag(char *s, parameter_t *parameter)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = parameter->plus_flag = 1;
		break;
	case ' ':
		i = parameter->space_flag = 1;
		break;
	case '#':
		i = parameter->hashtag_flag = 1;
		break;
	case '-':
		i = parameter->minus_flag = 1;
		break;
	case '0':
		i = parameter->zero_flag = 1;
		break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @parameter: the parameters struct
 * Return: if modifier was valid
 */

int get_modifier(char *s, parameter_t *parameter)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = parameter->h_modifier = 1;
		break;
	case 'l':
		i = parameter->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @parameter: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, parameter_t *parameter, va_list ap)
{
	int width = 0;

	if (*s == '*')
	{
		width = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			width = width * 10 + (*s++ - '0');
		}
	}

	parameter->width = width;
	return (s);
}

