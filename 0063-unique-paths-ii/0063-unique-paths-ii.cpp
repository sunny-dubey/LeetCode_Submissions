class Solution {
public:
    
    int check(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(n==0 and m==0)
            return 1;
        if(n<0 or m<0)
            return 0;
        
        
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int up = 0;
        int left = 0;
        if(n-1>=0 and grid[n-1][m]!=1)
            up = check(n-1,m,grid,dp);
        if(m-1>=0 and grid[n][m-1]!=1)
            left = check(n,m-1,grid,dp);
        
        return dp[n][m] = left + up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        if(grid[n-1][m-1]==1)
            return 0;
        
        int ans = check(n-1,m-1,grid,dp);
        return ans;
    }
};