#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int maxTriplets = numsSize * numsSize;
    int** ans = (int**)malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxTriplets * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        if (nums[i] > 0) break;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {

            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {

                ans[*returnSize] = (int*)malloc(3 * sizeof(int));
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[l];
                ans[*returnSize][2] = nums[r];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                l++;
                r--;

                while (l < r && nums[l] == nums[l - 1])
                    l++;

                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    return ans;
}