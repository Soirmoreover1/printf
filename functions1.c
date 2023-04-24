#include "main.h"

/**
 * P_char - print character
 *
 * @ap: argument pointer
 *
 * @parameter: the parameters struct
 *
 * Return: print bytes num
 */

int P_char(va_list ap, parameter_t *parameter)
{
	char pad_char = ' ';
	unsigned int pad = 1, count = 0, ch = va_arg(ap, int);

	if (parameter->minus_flag)
		count += _putchar(ch);
	while (pad++ < parameter->width)
		count += _putchar(pad_char);
	if (!parameter->minus_flag)
		count += _putchar(ch);
	return (count);
}

/**
 * P_string - print string
 *
 * @ap: argum pointer
 *
 * @parameter: the param struct
 *
 * Return: byte number
 */

int P_string(va_list ap, parameter_t *parameter)
{
	char *string = va_arg(ap, char *), pad_char = ' ';
	unsigned int padding = 0, count = 0, i = 0, j;

	(void)parameter;
	switch ((int)(!string))
	case 1:
		string = NULL_STRING;

	j = padding = _strlen(string);
	if (parameter->precision < padding)
		j = padding = parameter->precision;

	if (parameter->minus_flag)
	{
		if (parameter->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*string++);
		else
			count += _puts(string);
	}
	while (j++ < parameter->width)
		count += _putchar(pad_char);
	if (!parameter->minus_flag)
	{
		if (parameter->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				count += _putchar(*string++);
		else
			count += _puts(string);
	}
	return (count);
}

/**
 * print_S - custom format specifier
 *
 * @ap: argument pointer
 *
 * @parameter: the parameter struct
 *
 * Return:byte number
 */

int print_S(va_list ap, parameter_t *parameter)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, parameter);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

/**
 * P_int - print integer
 *
 * @ap: argument pointer
 *
 * @parameter: the param struct
 *
 * Return: bytes number
 */

int P_int(va_list ap, parameter_t *parameter)
{
	long num;

	if (parameter->l_modifier)
		num = va_arg(ap, long);
	else if (parameter->h_modifier)
		num = (short int)va_arg(ap, int);
	else
		num = (int)va_arg(ap, int);
	return (print_number(convert(num, 10, 0, parameter), parameter));
}

/**
 * P_percent - print string
 *
 * @ap: argument pointer
 *
 * @parameter: the parameter struct
 *
 * Return: bytes number
 */

int P_percent(va_list ap, parameter_t *parameter)
{
	(void)ap;
	(void)parameter;
	return (_putchar('%'));
}
