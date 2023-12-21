#include <stdio.h>

int main() {
    int totalDays;
    printf("Enter the total number of days: ");
    scanf("%d", &totalDays);
    int years = totalDays / 365;
    int weeks = (totalDays % 365) / 7;
    int remainingDays = (totalDays % 365) % 7;
    printf("Number of Years: %d\n", years);
    printf("Number of Weeks: %d\n", weeks);
    printf("Number of Days: %d\n", remainingDays);
    return 0;
}
