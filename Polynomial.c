#include <stdio.h>
#include <math.h>

int main() {
    int degree, i;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    double coefficients[degree + 1];
    printf("Enter the coefficients (from highest to lowest degree): ");
    for (i = degree; i >= 0; i--) {
        scanf("%lf", &coefficients[i]);
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    double result = 0;
    for (i = degree; i >= 0; i--) {
        result += coefficients[i] * pow(x, i);
    }
    printf("p(%lf) = %lf\n", x, result);
    return 0;
}
