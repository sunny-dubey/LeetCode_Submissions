class Solution {
public:
    
    int check(int n, int m, vector<vector<int>> &triangle,vector<vector<int>> &dp)
    {
        if(n==triangle.size()-1)
            return triangle[n][m];
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        int down = check(n+1,m,triangle,dp);
        int diagonal = check(n+1,m+1,triangle,dp);
        
        return dp[n][m] = triangle[n][m] + min(down,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        int ans = check(0,0,triangle,dp);
        return ans;
    }
};