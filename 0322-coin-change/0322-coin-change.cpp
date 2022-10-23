class Solution {
public:
    
    int check(int n, vector<int> &coins, int amount,vector<vector<int>> &dp)
    {
        if(n==0)
        {
           if(amount%coins[0]==0)
               return amount/coins[0];
            return 1e9;
        }
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        int exclude = 0 + check(n-1,coins,amount,dp);
        int include = INT_MAX;
        if(amount-coins[n]>=0)
           include = 1 + check(n,coins,amount-coins[n],dp);
        
        return dp[n][amount] = min(include,exclude);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        
        int ans = check(coins.size()-1,coins,amount,dp);
        if(ans>=1e9)
            return -1;
        return ans;
        
        
    }
};