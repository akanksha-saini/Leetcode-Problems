/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/

#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        if(n==0) return 0;
        
        int l_max [n], r_max[n]; int sum = 0, i;
        l_max[0] = height[0];
        r_max[n-1] = height[n-1];
        
        for(i=1; i<n; i++)
        {
            l_max[i] = std::max(l_max[i-1], height [i]);
        }
        
        for(i=n-2; i>=0; i--)
        {
            r_max[i] = std::max(r_max[i+1], height[i]);
        }
        for(i = 0 ; i<n; i++)
        {
            sum += (std::min(l_max[i], r_max[i]) - height[i]);
        }
        return sum;
        
    }
};
