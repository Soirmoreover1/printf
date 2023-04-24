#include "main.h"

/**
 * P_address - prints address
 * @ap: argument pointer
 * @parameter: the parameters struct
 * Return: bytes printed
 */

int P_address(va_list ap, parameter_t *parameter)
{
	unsigned long int value = va_arg(ap, unsigned long int);
	char *output;

	if (!value)
	{
		return (_puts("(nil)"));
	}

	output = convert(value, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameter);
	*--output = 'x';
	*--output = '0';
	return (print_number(output, parameter));
}


/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @parameter: paramater struct
 * Return: string
 */

char *convert(long int num, int base, int flags, parameter_t *parameter)
{
	static char *digits;
	static char buffer[50];
	char sign = 0;
	char *output;
	unsigned long value = num;
	(void)parameter;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		value = -num;
		sign = '-';
	}

	digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	output = &buffer[49];
	*output = '\0';

	do {
		*--output = digits[value % base];
		value /= base;
	} while (value != 0);

	if (sign)
	{
		*--output = sign;
	}

	return (output);
}

/**
 * P_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @param: the parameters struct
 * Return: bytes printed
 */

int P_unsigned(va_list ap, parameter_t *param)
{
	unsigned long value;

	if (param->l_modifier)
	{
		value = (unsigned long)va_arg(ap, unsigned long);
	}
	else if (param->h_modifier)
	{
		value = (unsigned short int)va_arg(ap, unsigned int);
	}
	else
	{
		value = (unsigned int)va_arg(ap, unsigned int);
	}

	param->unsign = 1;
	return (print_number(convert(value, 10, CONVERT_UNSIGNED, param), param));
}

