#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define FIELD_BUF_SIZE 50
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT                  \
	{                                \
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
	}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct containing format specifier parameters
 *
 * @unsign: flag indicating if an unsigned value is being processed
 *
 * @plus_flag: flag indicating if the plus flag was specified
 * @space_flag: flag indicating if the space flag was specified
 * @hashtag_flag: flag indicating if the hashtag flag was specified
 * @zero_flag: flag indicating if the zero flag was specified
 * @minus_flag: flag indicating if the minus flag was specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: flag indicating if the h modifier was specified
 * @l_modifier: flag indicating if the l modifier was specified
 */

typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} parameter_t;

/**
 * struct specifier - struct containing format specifier informa
 *
 * @specifier: format specifier token
 *
 * @f: function pointer associated with the specifier
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameter_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int P_char(va_list ap, parameter_t *parameter);
int P_int(va_list ap, parameter_t *parameter);
int P_string(va_list ap, parameter_t *parameter);
int P_percent(va_list ap, parameter_t *parameter);
int print_S(va_list ap, parameter_t *parameter);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, parameter_t *parameter);
int get_print_func(char *s, va_list ap, parameter_t *parameter);
int get_flag(char *s, parameter_t *parameter);
int get_modifier(char *s, parameter_t *parameter);
char *get_width(char *s, parameter_t *parameter, va_list ap);

/* number.c */
char *convert(long int num, int base, int flags, parameter_t *parameter);
int P_unsigned(va_list ap, parameter_t *param);
int P_address(va_list ap, parameter_t *parameter);

/* convert_number.c */
int P_hex(va_list ap, parameter_t *parameter);
int P_HEX(va_list ap, parameter_t *parameter);
int P_binary(va_list ap, parameter_t *parameter);
int P_octal(va_list ap, parameter_t *parameter);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameter_t *parameter);
int print_number_right_shift(char *str, parameter_t *parameter);
int print_number_left_shift(char *str, parameter_t *parameter);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int P_reverse(va_list ap, parameter_t *parameter);
int P_rot13(va_list ap, parameter_t *parameter);

/* parameter.c */
void init_parameter(parameter_t *parameter, va_list ap);

/* string_fields.c */
char *get_precision(char *p, parameter_t *parameter, va_list ap);

/* _prinf.c */
int _printf(const char *format, ...);

#endif
