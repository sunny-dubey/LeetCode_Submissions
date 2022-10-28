class Solution {
public:
    
    int check(int n, int m, vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(n==0 and m==0)
            return grid[0][0];
        if(n<0 or m<0)
            return 1e9;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int up = check(n-1,m,grid,dp);
        int left = check(n,m-1,grid,dp);
        
        return dp[n][m] = grid[n][m] + min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        int ans = check(n-1,m-1,grid,dp);
        return ans;
    }
};