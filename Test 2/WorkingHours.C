#include <stdio.h>
#include <math.h>

int main() 
{
    int hours, days, workers;
    double total_working_day, total_working_hour, hours_left, additional_hours;
    
    printf("Enter total number of hours needed: ");
    scanf("%d", &hours);
    
    printf("Enter number of days: ");
    scanf("%d", &days);
    
    printf("Enter number of workers: ");
    scanf("%d", &workers);
    
    total_working_day = days-(days*0.1); 
    total_working_hour = total_working_day*workers*8; 
    total_working_hour += total_working_day*workers*2; 

    if (total_working_hour >= hours) 
    {
        hours_left = total_working_hour - hours;
        printf("Yes! %.0f hours left!!!", floor(hours_left));
    } 
    
    else 
    {
        additional_hours = hours - total_working_hour;
        printf("Not enough time! %.0f hours needed!!!", floor(additional_hours));
    }
    
    return 0;
}
