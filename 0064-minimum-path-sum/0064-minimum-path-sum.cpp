class Solution {
public:
    
    int check(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==0 and j==0)
            return grid[0][0];
        if(i<0 or j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left = INT_MAX;
        int right = INT_MAX;
        if(i-1>=0)
            left = check(i-1,j,grid,dp);
        if(j-1>=0)
            right = check(i,j-1,grid,dp);
        
        int ans = grid[i][j] + min(left,right);
        return dp[i][j] =  ans;
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        return check(m-1,n-1,grid,dp);
    }
};