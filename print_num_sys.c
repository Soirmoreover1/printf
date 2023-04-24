#include "main.h"

/**
 * P_hex - print unsigned hex num in lowercase
 *
 * @ap: the argu pointer
 *
 * @parameter: the para struct
 *
 * Return: bytes printed
 */

int P_hex(va_list ap, parameter_t *parameter)
{
	unsigned long num;
	int count = 0;
	char *ostring;

	if (parameter->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (parameter->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);

	ostring = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameter);
	if (parameter->hashtag_flag && num)
	{
		*--ostring = 'x';
		*--ostring = '0';
	}
	parameter->unsign = 1;
	count += print_number(ostring, parameter);

	return (count);
}

/**
 * P_HEX - prints unsigned hex num in uppercase
 *
 * @ap: the argu pointer
 *
 * @parameter: the para struct
 *
 * Return: byte printed
 */

int P_HEX(va_list ap, parameter_t *parameter)
{
	unsigned long num;
	int count = 0;
	char *output_str;

	if (parameter->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (parameter->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);

	output_str = convert(num, 16, CONVERT_UNSIGNED, parameter);
	if (parameter->hashtag_flag && num)
	{
		*--output_str = 'X';
		*--output_str = '0';
	}
	parameter->unsign = 1;
	count += print_number(output_str, parameter);

	return (count);
}

/**
 * P_binary - prints unsigned binary number
 *
 * @ap: the argument pointer
 *
 * @parameter: the parameters struct
 *
 * Return: bytes printed
 */

int P_binary(va_list ap, parameter_t *parameter)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *output_str = convert(num, 2, CONVERT_UNSIGNED, parameter);
	int count = 0;

	if (parameter->hashtag_flag && num)
		*--output_str = '0';

	parameter->unsign = 1;
	count += print_number(output_str, parameter);

	return (count);
}

/**
 * P_octal - print unsigned octal num
 *
 * @ap: the argu pointer
 *
 * @parameter: the para struct
 *
 * Return: byte printed
 */

int P_octal(va_list ap, parameter_t *parameter)
{
	unsigned long num;
	int count = 0;
	char *output_str;


	if (parameter->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (parameter->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);

	output_str = convert(num, 8, CONVERT_UNSIGNED, parameter);

	if (parameter->hashtag_flag && num)
		*--output_str = '0';

	parameter->unsign = 1;
	count += print_number(output_str, parameter);

	return (count);
}
