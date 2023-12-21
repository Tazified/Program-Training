#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checking_password(char password[]) 
{
    if (strlen(password) < 8) 
    {
        return 0;
    } 

    else 
    {
        int l_case=0, u_case=0, special=0, digit=0;
        for (int i=0; password[i]!='\0'; i++) 
        {
            if (islower(password[i])) 
            {
                l_case=1;
            } 
            else if (isupper(password[i])) 
            {
                u_case=1;
            } 
            else if (strchr("!@#$%^&*({[]})-_/?+", password[i]) != NULL)
            {
                special=1;
            } 
            else if (isdigit(password[i])) 
            {
                digit=1;
            }
        }

        if (l_case && u_case && special && digit) 
        {
            return 1;
        }
    }

    return 0;
}

int main() 
{
    char password[50];

    printf("Enter the password: ");
    scanf("%s", password);

    if (checking_password(password)) 
    {
        printf("STRENGTH: STORNG PASSWORD!!!");
    } 
    else
    {
        printf("STRENGTH: WEAK PASSWORD!!!!");
    }

    return 0;
}
