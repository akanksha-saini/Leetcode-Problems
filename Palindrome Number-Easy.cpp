class Solution {
public:
    bool isPalindrome(int x) {
        
        long long int d, rev=0; int num = x;
        
        if(x<0)
        {
          return false;  
        }
             
        while(x!=0)
        {
            d = x%10;
            rev = (rev *10) + d;
            x = x/10;
        }
        if(rev == num)
             return true;
        else
            return false;
    }
};
