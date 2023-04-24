#include "main.h"

/**
 * init_parameter - clears struct fields and reset buf
 * @parameter: the parameters struct
 * @ap: the argument pointer
 */

void init_parameter(parameter_t *parameter, va_list ap)
{
	parameter->unsign = 0;

	parameter->plus_flag = 0;
	parameter->space_flag = 0;
	parameter->hashtag_flag = 0;
	parameter->zero_flag = 0;
	parameter->minus_flag = 0;

	parameter->width = 0;
	parameter->precision = UINT_MAX;

	parameter->h_modifier = 0;
	parameter->l_modifier = 0;
	(void)ap;
}

