#include <stdlib.h>
#include <time.h>
/**
 * main - generates keygen.
 * Return: 0 Always.
 */
int main(void)
{
	int x = 0, y = 0;
	time_t t;

	srand((unsigned int) time(&t));
	while (c < 2772)
	{
		x = rand() % 128;
		if ((y + x) > 2772)
			break;
		y = y + x;
		printf("%y", x);
	}
	printf("%y\n", (2772 - y));
	return (0);
}
