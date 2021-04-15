/*
https://leetcode.com/problems/rotting-oranges/
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 */

class fruit
{
    public:
      int x,y,t;
    fruit(int a, int b, int c)
    {
        x = a; y = b; t = c;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<fruit> q; // we have to use queue because oranges which are rotten first will   rot                             it's neighbour first (FIFO)
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        //insert rotten oranges first in q
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                {
                    fruit f(i,j,0);
                    q.push(f);
                }    
            }
        }
        //check the neighbour cells if they have fresh orange or not i.e., they have 1 or not
        
        while(!q.empty())//q should not be empty
        {
            fruit f = q.front(); //get front element and check it's adjacent
            q.pop();
            int x = f.x;
            int y = f.y;
            int t = f.t;
            
            ans = max(ans,t); //max time will be stored
            
            //check downward orange
            if(x+1<row && grid[x+1][y] == 1 )
            {
                grid[x+1][y] = 2;
                fruit f1(x+1,y,t+1);
                q.push(f1);
            }
            
            //check upward orange
            if(x-1 >=0 && grid[x-1][y] == 1 )
            {
                grid[x-1][y] = 2;
                fruit f1(x-1,y,t+1);
                q.push(f1);
            }
            
            
            //check left
            if(y-1>=0 && grid[x][y-1] == 1)
            {
                grid[x][y-1] = 2;
                fruit f1(x,y-1,t+1);
                q.push(f1);
            }
            
            //check right
            if(y+1<col && grid[x][y+1]== 1)
            {
                grid[x][y+1] = 2;
                fruit f1(x,y+1,t+1);
                q.push(f1);
            }
        }
        
        //whether there is any fresh orange left or not
       for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                    
                }    
            }
        }
        return ans;
    }
};
