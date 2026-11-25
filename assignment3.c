#include <stdio.h>

int main()
{
    int math;
    int a, b, result;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Enter math operation number (1-5): ");
    scanf("%d", &math);

    switch(math)
    {
        case 1:
            result = a + b;
            printf("Addition = %d", result);
            break;

        case 2:
            result = a - b;
            printf("Subtraction = %d", result);
            break;

        case 3:
            result = a * b;
            printf("Multiplication = %d", result);
            break;

        case 4:
            if(b != 0)
            {
                result = a / b;
                printf("Division = %d", result);
            }
            else
            {
                printf("Division by zero is not possible");
            }
            break;

        case 5:
            result = a % b;
            printf("Remainder = %d", result);
            break;

        default:
            printf("Invalid math operation number");
    }

    return 0;
}
