class Solution {
public:
    
    int check(int n, int m,vector<vector<int>> &dp)
    {
        if(n==0 and m==0)
            return 1;
        if(n<0 or m<0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int up = check(n-1,m,dp);
        int left = check(n,m-1,dp);
        
        return dp[n][m] = up + left;
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[0][i] = 1;
        }
        for(int i=0;i<m;i++)
        {
            dp[i][0] =1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};