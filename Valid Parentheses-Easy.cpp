/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
*/
class Solution {
public:
    bool isValid(string str) {
        
        stack<int> s;
        int n = str.length();
        
        for(int i=0; i<n; i++)
        {
            if(s.empty())
                s.push(str[i]);
           
            else
            {
               if(str[i]=='{' || str[i]=='(' || str[i]=='[')
                s.push(str[i]);
            
            if(str[i]=='}')
            {
                if(!s.empty() && s.top() != '{')
                    return false;
                s.pop();
            }
            else if(str[i]==']')
            {
                if(!s.empty() && s.top() != '[')
                    return false;
                s.pop();
            }
            else if(str[i]==')')
            {
                if(!s.empty() && s.top() != '(')
                    return false;
                s.pop();
            }
             
            }
            
            
        }
        if(s.empty())
            return true;
        return false;
    }
};
