class Solution {
public:
    
    int check(int n, int buy,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(n>=nums.size())
            return 0;
        
        if(dp[n][buy]!=-1)
            return dp[n][buy];
        
        int profit = 0;
        
        if(buy)
            profit = max(-nums[n] + check(n+1,0,nums,dp), 0 + check(n+1,1,nums,dp));
        else{
            profit = max(nums[n] + check(n+2,1,nums,dp), 0 + check(n+1,0,nums,dp));
        }
        return dp[n][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        
        return check(0,1,prices,dp);
    }
};