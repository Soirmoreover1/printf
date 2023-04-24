#include "main.h"

/**
 * get_precision - gets the precision from the format string
 *
 * @p: the format stri
 *
 * @parameter: the param struct
 *
 * @ap: the argum pointer
 *
 * Return: new pointer
 */

char *get_precision(char *p, parameter_t *parameter, va_list ap)
{
	int precision = 0;

	if (*p != '.')
	{
		return (p);
	}

	p++;
	if (*p == '*')
	{
		precision = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		{
			precision = precision * 10 + (*p++ - '0');
		}
	}

	parameter->precision = precision;
	return (p);
}
