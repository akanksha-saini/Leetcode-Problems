/*Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1]
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int> a; 
        
        int complement; //use complement approach
        
        for(int i=0; i<nums.size(); i++)
        {
           complement = target - nums[i]; //target - current element
            
          auto address =  std::find(nums.begin(),nums.end(),complement); //find if complement exists in array or not
        
            if(address != nums.end() &&  (address - nums.begin() != i)) //if address is equal to nums.end() then complement is not found, address- base address will return index of complement
            {    //address - nums.begin() != current element because of unique element pair condition
                a.push_back(i); //push_back() adds the i index into vector a 
                a.push_back(address-nums.begin()); //adds complement index into vector a
                return a;
            }
        }
        return a;
 
    }
   };
