class Solution {
public:
    
    int check(int n, int prev, vector<int> &nums,vector<vector<int>> &dp)
    {
        if(n==nums.size())
            return 0;
        
        if(dp[n][prev+1]!=-1)
            return dp[n][prev+1];
        
        int exclude = 0 + check(n+1,prev,nums,dp);
        int include = 0;
        if(prev==-1 || nums[n]>nums[prev])
            include = 1 + check(n+1,n,nums,dp);
        
        return dp[n][prev+1]= max(include,exclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return check(0,-1,nums,dp);
    }
};