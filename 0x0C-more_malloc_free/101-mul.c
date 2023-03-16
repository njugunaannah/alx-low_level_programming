#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *num1_str, *num2_str;
    int num1, num2, result, i;

    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    num1_str = argv[1];
    num2_str = argv[2];

    for (i = 0; num1_str[i] != '\0'; i++) {
        if (!isdigit(num1_str[i])) {
            printf("Error\n");
            return 98;
        }
    }

    for (i = 0; num2_str[i] != '\0'; i++) {
        if (!isdigit(num2_str[i])) {
            printf("Error\n");
            return 98;
        }
    }

    num1 = atoi(num1_str);
    num2 = atoi(num2_str);

    result = num1 * num2;
    printf("%d\n", result);

    return 0;
}
