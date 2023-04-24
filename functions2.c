#include "main.h"

/**
 * P_rot13 - prints a string using rot13 encryption
 * @ap: list of arguments
 * @parameter: parameters
 * Return: printed bytes number
 */

int P_rot13(va_list ap, parameter_t *parameter)
{
	char *input_string = va_arg(ap, char *);
	int i, j, count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)parameter;

	if (input_string == NULL)
		input_string = "(null)";

	for (i = 0; input_string[i] != '\0'; i++)
	{
		for (j = 0; in[j] != '\0'; j++)
		{
			if (input_string[i] == in[j])
			{
				count += _putchar(out[j]);
				break;
			}
		}
		if (in[j] == '\0')
			count += _putchar(input_string[i]);
	}

	return (count);
}

/**
 * P_reverse - prints a string in reverse
 * @ap: list of arguments
 * @parameter: parameters
 * Return: printed bytes count
 */

int P_reverse(va_list ap, parameter_t *parameter)
{
	char *input_string = va_arg(ap, char *);
	int i, length, count = 0;

	(void)parameter;

	if (input_string == NULL)
		input_string = "(null)";

	for (length = 0; input_string[length] != '\0'; length++)
		;

	for (i = length - 1; i >= 0; i--)
		count += _putchar(input_string[i]);

	return (count);
}

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: printed bytes number
 */

int print_from_to(char *start, char *stop, char *except)
{
	int count = 0;

	while (start <= stop)
	{
		if (start != except)
		{
			count += _putchar(*start);
		}
		start++;
	}
	return (count);
}

