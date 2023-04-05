#include "main.h"

/**
 * _puts_recursion - to print a string followed by a new line | puts with recursion
 * @s: string
 * Return: no return
 */
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
