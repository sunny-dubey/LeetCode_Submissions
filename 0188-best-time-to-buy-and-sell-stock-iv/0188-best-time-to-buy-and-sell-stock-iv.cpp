class Solution {
public:
    
    int check(int n, int buy, int cap, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        if(cap==0)
            return 0;
        if(n==nums.size())
            return 0;
        if(dp[n][buy][cap]!=-1)
            return dp[n][buy][cap];
        
        int profit = 0;
        
        if(buy)
            profit = max(-nums[n] + check(n+1,0,cap,nums,dp), 0 + check(n+1,1,cap,nums,dp));
        else
            profit = max(nums[n] + check(n+1,1,cap-1,nums,dp), 0 + check(n+1,0,cap,nums,dp));
        
        return dp[n][buy][cap] = profit;
            
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(3,vector<int>(k+1,-1)));
        
        return check(0,1,k,prices,dp);
        
    }
};