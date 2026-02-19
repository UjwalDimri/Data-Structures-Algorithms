// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:

// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:

// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total_sum = 0;
    
    int current_max = nums[0];
    int max_sum = nums[0];
    
    int current_min = nums[0];
    int min_sum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        
        total_sum += nums[i];
        
        if(i > 0) {
            // Maximum subarray (Kadane)
            if(current_max + nums[i] > nums[i])
                current_max = current_max + nums[i];
            else
                current_max = nums[i];
                
            if(current_max > max_sum)
                max_sum = current_max;
            
            
            // Minimum subarray
            if(current_min + nums[i] < nums[i])
                current_min = current_min + nums[i];
            else
                current_min = nums[i];
                
            if(current_min < min_sum)
                min_sum = current_min;
        }
    }
    
    // If all elements are negative
    if(max_sum < 0)
        return max_sum;
    
    // Return maximum of normal and circular
    if(max_sum > total_sum - min_sum)
        return max_sum;
    else
        return total_sum - min_sum;
}