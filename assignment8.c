
#include <stdio.h>

// Function to swap motor speeds
void swap(int *p1, int *p2)
{
    int temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int motor1, motor2;
    int *p1, *p2;
    int original1, original2;

    printf("Enter speed of Motor 1 (RPM): ");
    scanf("%d", &motor1);

    printf("Enter speed of Motor 2 (RPM): ");
    scanf("%d", &motor2);

    original1 = motor1;
    original2 = motor2;

    p1 = &motor1;
    p2 = &motor2;

    printf("\nBefore Swapping:\n");
    printf("Motor 1 Speed = %d RPM\n", motor1);
    printf("Motor 2 Speed = %d RPM\n", motor2);

    printf("Address of Motor 1 = %p\n", (void*)p1);
    printf("Address of Motor 2 = %p\n", (void*)p2);

    swap(p1, p2);

    printf("\nAfter Swapping:\n");
    printf("Motor 1 Speed = %d RPM\n", motor1);
    printf("Motor 2 Speed = %d RPM\n", motor2);

    printf("Address of Motor 1 = %p\n", (void*)p1);
    printf("Address of Motor 2 = %p\n", (void*)p2);

    if (motor1 == original2 && motor2 == original1)
    {
        printf("\nMotor speeds swapped successfully!");
    }
    else
    {
        printf("\nSwapping failed!");
    }

    return 0;
}

