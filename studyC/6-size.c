#include <stdio.h>
/**
 * main - Entry point
 * description: a program
 * Return: always 0(success)
 */
int main(void)
{
	int a;
	long int b;
	long long int c;
	char d;
	float f;
	double e;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(d));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(a));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(b));
	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
	return (0);
}
