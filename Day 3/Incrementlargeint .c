#include <stdio.h>
#include <stdlib.h>

int* increment(int* digits, int n, int* resultSize) {  
    int i,j;
    for (i = n - 1; i >= 0; i--) {
        digits[i] += 1;
        if (digits[i] == 10) {
            digits[i] = 0;
        } else {
            break;
        }
    }
    if (digits[0] == 0) {
        *resultSize = n + 1;
        int* result = (int*)malloc((*resultSize) * sizeof(int));
        result[0] = 1;
        for (j = 1; j < *resultSize; j++) {
            result[j] = digits[j - 1];
        }
        return result;
    } else {
        *resultSize = n;
        return digits;
    }
}

int main() {
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* digits = (int*)malloc(n * sizeof(int));
    printf("Enter the array elements (from most significant to least significant): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
    }

    int resultSize;
    int* result = increment(digits, n, &resultSize);

    printf("Result: [");
    for (i = 0; i < resultSize; i++) {
        printf("%d", result[i]);
        if (i < resultSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(digits);
    free(result);

    return 0;
}

