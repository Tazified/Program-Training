#include <stdio.h>

int main() {
    int n = 5,i,j;
    int odd=1,even=2;
    for (i = 1; i <= n; i++) {
        int start = odd;
        int space = n - i;  
        for (j = 1; j <= space; j++) {
            printf("  ");  
        }
        if(i%2!=0){
        for (j = 1; j <= i; j++) {
            printf("%d ", odd);
            odd += 2;
        }}
        if(i%2==0){
        for (j = 1; j <= i; j++) {
            printf("%d ", even);
            even += 2;
        }
        }
        printf("\n");
    }

    return 0;
}
