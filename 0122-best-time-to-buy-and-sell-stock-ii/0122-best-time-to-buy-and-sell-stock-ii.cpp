class Solution {
public:
    
    int check(int n, int buy, vector<int> &prices,vector<vector<int>> &dp)
    {
        if(n==prices.size())
            return 0;
        if(dp[n][buy]!=-1)
            return dp[n][buy];
        int profit = 0;
        
        if(buy)
            profit = max(-prices[n] + check(n+1,0,prices,dp), 0 + check(n+1,1,prices,dp));
        else
            profit = max(prices[n] + check(n+1,1,prices,dp),0 + check(n+1,0,prices,dp));
        return  dp[n][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return check(0,1,prices,dp);
        
    }
};