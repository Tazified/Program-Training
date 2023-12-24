#include <stdio.h>

void findSecondLargest(int arr[], int n) {
    int i,firstMax = arr[0];
    int secondMax = -1;

    for (i = 1; i < n; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] < firstMax && (secondMax == -1 || arr[i] > secondMax)) {
            secondMax = arr[i];
        }
    }

    if (secondMax == -1) {
        printf("No second largest distinct element found.\n");
    } else {
        printf("Second largest distinct element: %d\n", secondMax);
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int i,Arr[N];
    printf("Enter the elements of the array: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }

    findSecondLargest(Arr, N);

    return 0;
}

