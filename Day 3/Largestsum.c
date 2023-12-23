#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int i,maxSum = nums[0];
    int currentSum = nums[0];
    for (i = 1; i < numsSize; ++i) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }
    return maxSum;
}

int main() {
    int i,numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the array elements: ");
    for (i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Maximum Subarray Sum: %d\n", maxSubArray(nums, numsSize));
    free(nums);
    return 0;
}

