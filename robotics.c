
#include <stdio.h>

struct Robot {
    int robotId;
    char robotType[50];
    float payloadCapacity;
    float actualLoad;
    float operatingTime;
    float utilization;
};

int main() {
    struct Robot r[100];
    int n, i;

    printf("Enter the number of robot arms: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of robots!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Robot %d:\n", i + 1);

        printf("Robot ID: ");
        scanf("%d", &r[i].robotId);

        printf("Robot Type: ");
        scanf(" %49[^\n]", r[i].robotType);

        printf("Payload Capacity (kg): ");
        scanf("%f", &r[i].payloadCapacity);

        printf("Actual Load (kg): ");
        scanf("%f", &r[i].actualLoad);

        printf("Operating Time (hours): ");
        scanf("%f", &r[i].operatingTime);

        if (r[i].payloadCapacity <= 0 ||
            r[i].actualLoad < 0 ||
            r[i].operatingTime < 0) {
            printf("Invalid robot data!\n");
            return 1;
        }
        r[i].utilization =
            (r[i].actualLoad / r[i].payloadCapacity) * 100;
    }

    for (i = 0; i < n; i++) {
        printf("\nRobot ID: %d\n", r[i].robotId);
        printf("Robot Type: %s\n", r[i].robotType);
        printf("Payload Capacity: %.2f kg\n",
               r[i].payloadCapacity);
        printf("Actual Load: %.2f kg\n", r[i].actualLoad);
        printf("Operating Time: %.2f hours\n",
               r[i].operatingTime);
        printf("Load Utilization: %.2f%%\n",
               r[i].utilization);

        if (r[i].actualLoad > r[i].payloadCapacity) {
            printf("Status: OVERLOADED - Beyond rated payload!\n");
        } else {
            printf("Status: Within rated payload.\n");
        }
    }

    return 0;
}

