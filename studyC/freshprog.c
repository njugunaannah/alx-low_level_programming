#include <stdio.h>
/**
 * main - Entry point
 * description: examining a new program
 * Return: always 0 (success)
 */
int main(void)
{
	char name[100];
	int age;

	printf("Enter age: ");
	scanf("%d", &age);
	printf("Enter name: ");
	scanf("%s", name);

	printf("Your name is: %s, you are: %d\n", name, age);
	return (0);
}

