#include <stdio.h>
#include <stdlib.h>

int canJump(int* nums, int numsSize) {
    int i,farthest = 0;

    for (i = 0; i < numsSize - 1; ++i) {
        if (i > farthest) {
            return 0; 
        }
        farthest = (farthest > i + nums[i]) ? farthest : i + nums[i];

        if (farthest >= numsSize - 1) {
            return 1; 
        }
    }
    return farthest >= numsSize - 1;
}

int main() {
    int numsSize,i;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the array elements: ");
    for (i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Result: %s\n", canJump(nums, numsSize) ? "true" : "false");
    free(nums);
    return 0;
}

