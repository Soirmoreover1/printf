#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: format string
 * Return: printed bytes number
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list arg_list;
	char *p, *start;
	parameter_t parameters = PARAMS_INIT;

	va_start(arg_list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_parameter(&parameters, arg_list);
		if (*p != '%')
		{
			count += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &parameters))
			p++;
		p = get_width(p, &parameters, arg_list);
		p = get_precision(p, &parameters, arg_list);
		if (get_modifier(p, &parameters))
			p++;
		if (!get_specifier(p))
			count += print_from_to(start, p,
								   parameters.l_modifier || parameters.h_modifier ? p - 1 : 0);
		else if (*p == 's' && parameters.minus_flag)
			count += P_reverse(arg_list, &parameters);
		else
			count += get_print_func(p, arg_list, &parameters);
	}
	_putchar(BUF_FLUSH);
	va_end(arg_list);
	return (count);
}

