
// Week 0 - Moving Zeroes | 25-Sept-24
// Leetcode function that moves all the zeroes in an array to the right

void moveZeroes(int* nums, int numsSize) {
    int n=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]!=0){
            nums[n]=nums[i];
            n++;
        }
    }
    for(int j=n; j<numsSize; j++){
        nums[j]=0;
    }
}
