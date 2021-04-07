class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        
        int length = nums.size();
       return length;
    }
    
};
