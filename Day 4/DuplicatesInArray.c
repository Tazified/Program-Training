#include <stdio.h>
void findDuplicates(int arr[], int N) {
    int *count = (int *)calloc(N, sizeof(int));
    printf("Duplicates: ");
    int i,found = 0;
    for (i = 0; i < N; i++) {
        count[arr[i]]++;
        if (count[arr[i]] == 2) {
            if (found > 0) {
                printf(" ");
            }
            printf("%d", arr[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("-1");
    }
    free(count);
}
int main() {
    int i,N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements of the array (0 to N-1): ");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    findDuplicates(arr, N);
    return 0;
}
