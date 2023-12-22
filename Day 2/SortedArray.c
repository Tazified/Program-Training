#include <stdio.h>
void printDuplicateFrequency(int arr[], int n) {
 int i = 0;
 while (i < n) {
 int count = 1;
 while ((i < n - 1) && (arr[i] == arr[i + 1])) {
 count++;
 i++;
 }
 if (count > 1) {
 printf("%d->%d", arr[i], count);
 if (i < n - 1) {
 printf(",");
 }
 }
 i++;
 }
 printf("\n");
}
int main() {
 int n;
 printf("Enter the size of the array: ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter the sorted array elements:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("Sample Output:\n");
 printDuplicateFrequency(arr, n);
return 0;
}
