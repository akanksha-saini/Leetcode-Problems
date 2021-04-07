/*https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:
Input: nums = [1]
Output: 1

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int current_sum = 0, max_sum = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
        {
            current_sum += nums[i];
            if(max_sum < current_sum)
                max_sum = current_sum;
            
            if(current_sum < 0)
                current_sum = 0;
        }
        return max_sum;
    }
};
