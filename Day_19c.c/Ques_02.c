#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int curr_max = 0, max_sum = nums[0];
    int curr_min = 0, min_sum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];

        // Kadane for maximum subarray
        curr_max = max(nums[i], curr_max + nums[i]);
        max_sum = max(max_sum, curr_max);

        // Kadane for minimum subarray
        curr_min = min(nums[i], curr_min + nums[i]);
        min_sum = min(min_sum, curr_min);
    }

    // If all numbers are negative
    if (max_sum < 0)
        return max_sum;

    // Return maximum of normal and circular case
    return max(max_sum, total - min_sum);
}