void moveZeroes(int* nums, int numsSize){
    int pos = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

    for (int i = pos; i < numsSize; i++) {
        nums[i] = 0;
    }
}