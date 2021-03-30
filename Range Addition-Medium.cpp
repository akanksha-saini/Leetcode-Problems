/*
https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/370-range-addition-medium.html
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3] */

//Sol : 

#include <iostream>
#include<vector>
using namespace std;

vector<int> range_addition(int n, vector<vector<int>> & updates)
{
   vector<int> a(n,0);
   
   int k = updates.size();
   int start, end, val;
   
   for(int i=0; i<k; i++)
   {
            start = updates[i][0];
           end = updates[i][1];
            val = updates[i][2];
            
            a[end] += val;
            if(start != 0)
               a[start-1] -= val;
            
       
   }
  
  for(int i= n-2 ; i>=0; i--)
   {
       a[i] += a[i+1];
              
   }
   
   return a;
   
}
int main()
{
    int n;
    cin>>n;                                
    //vector<int> arr(n); 
    int k;
    cin>>k; //k operations
    
    vector<vector<int>> updates;
    vector<int> v, a; 
    int val;
  for(int j=0; j<k; j++)
  {
      v.clear();
      for(int i=0; i<3; i++)
      {
        cin>>val;
        v.push_back(val);
     }
     updates.push_back(v);
  }
    
    
    a = range_addition(n,updates);
   for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
   
    return 0;
}


    
    
