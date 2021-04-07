class Solution {
public:
     int reverse(int x) {
     
        long int d, rev =0; 
        while(x!=0)
        {   
            if(rev>INT_MAX/10 || rev<INT_MIN/10)
                return 0;
            else{
               d = x%10;
               rev = (rev*10) + d;
               x = x/10; 
            }
            
        }
        return rev;
    }
};
