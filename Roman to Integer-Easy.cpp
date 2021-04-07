/*
https://leetcode.com/problems/roman-to-integer/
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


Given a roman numeral, convert it to an integer.
Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4
*/
#include <bits/stdc++.h>
class Solution {
public:
   int romanToInt(string s) {
     
        int n = s.length();
        
        
        unordered_map<char, int> myMap;
        
    //pair<string,int>  p("I", 1);
          //myMap.insert(p);
            myMap['I'] = 1;
            myMap['V'] = 5;
            myMap['X'] = 10;
            myMap['L'] = 50;
            myMap['C'] = 100;
            myMap['D'] = 500;
            myMap['M']  = 1000;
          int res =0;  
        for(int i =0; i<n; i++)
        {
            //std::string l = s.substr(i,1) , r = s.substr(i+1,1);        
            if(myMap[s[i]] < myMap[s[i+1]])
            {
                 res += myMap[s[i+1]] - myMap[s[i]];
                i++;
                continue;
            }
            res += myMap[s[i]]; 
                
        }
        return res;
        
    }    
};
