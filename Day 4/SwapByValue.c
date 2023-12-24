#include <stdio.h>
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swapByValue(num1, num2);
    printf("After swapping (call by value): num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}
