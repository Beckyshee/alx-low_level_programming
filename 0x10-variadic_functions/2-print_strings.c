#include "variadic_functions.h"
/**
 * print_strings - prints strings.
 * @separator: string to be printed between the strings.
 * @n: number of strings passed to the function.
 *
 * Return: no return.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list valistrg;
	unsigned int m;
	char *str;

	va_start(valistrg, n);

	for (m = 0; m < n; m++)
	{
		str = va_arg(valistrg, char *);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");

		if (m < n - 1)
			if (separator)
				printf("%s", separator);
	}

	printf("\n");
	va_end(valistrg);
}

