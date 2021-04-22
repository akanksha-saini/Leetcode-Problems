/*
There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

 

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]


*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        /*
          in XOR if two elements are different then we get true otherwise false. ex - 1^1 = 0 , 1^0 = 1
          
          a^b = c
          So, in XOR if we have any two of the element between a,b,c then we get the other ex- b^c = a and a^c = b, 
          also in XOR order doesn't matter. (a^b = b^a).
          
          ATQ, 
          output[0] = first //given
          output[0+1] = encoded[0] ^ output[0]
          output[1+1] = encoded[1] ^ output[1]
          output[2+1] = encoded[2] ^ output[2]
           and soon..
        
        */
        
        vector<int> output;
        output.push_back(first);
        for(int i=0; i<encoded.size(); i++)
        {
            output.push_back(encoded[i]^output[i]);
        }
        
        return output;
    }
};
