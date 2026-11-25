
#include <stdio.h>
#include <string.h>

#define MOISTURE_LIMIT 30.0
#define HEALTH_LIMIT 70

typedef struct {
    int id;
    float moisture, temperature, humidity;
    int cropHealth;
    float latitude, longitude;
} FieldRecord;

void addRecord() {
    FILE *fp = fopen("field_data.txt", "a");

    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return;
    }

    FieldRecord r;

    printf("\nEnter Field ID: ");
    scanf("%d", &r.id);

    printf("Enter Soil Moisture (%%): ");
    scanf("%f", &r.moisture);

    printf("Enter Temperature (C): ");
    scanf("%f", &r.temperature);

    printf("Enter Humidity (%%): ");
    scanf("%f", &r.humidity);

    printf("Enter Crop Health (%%): ");
    scanf("%d", &r.cropHealth);

    printf("Enter Latitude: ");
    scanf("%f", &r.latitude);

    printf("Enter Longitude: ");
    scanf("%f", &r.longitude);

    fprintf(fp, "%d %f %f %f %d %f %f\n",
            r.id, r.moisture, r.temperature,
            r.humidity, r.cropHealth,
            r.latitude, r.longitude);

    fclose(fp);

    printf("\nField Reading Saved Successfully!\n");
}

void generateReport() {
    FILE *fp = fopen("field_data.txt", "r");

    if (fp == NULL) {
        printf("\nNo Readings to Generate\n");
        return;
    }

    FieldRecord r;
    int count = 0;

    printf("\n========== FIELD REPORT ==========\n");

    while (fscanf(fp, "%d %f %f %f %d %f %f",
                  &r.id, &r.moisture, &r.temperature,
                  &r.humidity, &r.cropHealth,
                  &r.latitude, &r.longitude) == 7) {

        count++;

        printf("\nField ID: %d\n", r.id);
        printf("Soil Moisture: %.2f%%\n", r.moisture);
        printf("Temperature: %.2f C\n", r.temperature);
        printf("Humidity: %.2f%%\n", r.humidity);
        printf("Crop Health: %d%%\n", r.cropHealth);
        printf("Latitude: %.4f\n", r.latitude);
        printf("Longitude: %.4f\n", r.longitude);

        if (r.moisture < MOISTURE_LIMIT)
            printf("Soil Status: LOW MOISTURE - Irrigation Needed\n");
        else
            printf("Soil Status: MOISTURE NORMAL\n");

        if (r.cropHealth < HEALTH_LIMIT)
            printf("Crop Status: POOR HEALTH - Inspection Needed\n");
        else
            printf("Crop Status: HEALTHY\n");
    }

    if (count == 0)
        printf("\nNo valid records found.\n");

    printf("\nTotal Fields Recorded: %d\n", count);
    printf("==================================\n");

    fclose(fp);
}

int main() {
    int ch;

    while (1) {
        printf("\n--- Smart Agri Robot ---\n");
        printf("1. Add Field Reading\n");
        printf("2. Generate Report\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            addRecord();

        else if (ch == 2)
            generateReport();

        else if (ch == 3) {
            printf("\nExiting Smart Agri Robot...\n");
            break;
        }

        else
            printf("\nInvalid Choice! Try Again.\n");
    }

    return 0;
}

