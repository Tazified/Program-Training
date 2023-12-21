#include <stdio.h>

int main() 
{
    int x, y, z;
    printf("Enter the X value:");
    scanf("%d", &x);
    printf("Enter the Y value:");
    scanf("%d", &y);
    printf("Enter the Z value:");
    scanf("%d", &z);
    if ((x>y && x<z) || (x<y && x>z))
        printf("1");
    else if ((y>x && y<z) || (y<x && y>z))
        printf("2");
    else
        printf("3");
    
    return 0;
}
