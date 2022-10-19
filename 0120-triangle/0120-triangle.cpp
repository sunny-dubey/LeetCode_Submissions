class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[n-1][i] = nums[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                
                dp[i][j] = nums[i][j] + min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};