/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
    
        //total no of ASCII charcaters are 256 (0 - 255)
       int count[256] = {0}; //keeps track of frequency of characters appearing in string from left to right
       int used[256] = {0}; //keeps track of stack elements stored by checking string
        
        stack<char> st;
        
        for(int i=0; i<s.length(); i++)
            count[s[i]]++;
        
        for(int i=0; i<s.length(); i++)
        {
            count[s[i]]--;
            
            if(used[s[i]])
                continue;
          
               
            
                while(!st.empty() && count[st.top()] && st.top() > s[i])
                {
                    used[st.top()] = 0;
                    st.pop();
                    
                    
                }
            
            st.push(s[i]);
               
            used[s[i]] = 1;
        }
        string str;
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
       reverse(str.begin(),str.end());
        return str;
    }
};
