#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int number, fact;

    printf("Enter number: ");
    scanf("%d", &number);

    fact = factorial(number);

    printf("The factorial of %d is: %d\n", number, fact);

    return 0;
}
