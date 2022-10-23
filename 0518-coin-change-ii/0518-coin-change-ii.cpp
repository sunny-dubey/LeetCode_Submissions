class Solution {
public:
    
    int check(int n, int amount, vector<int> &coins,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return (amount%coins[0]==0);
        }
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        int exclude = check(n-1,amount,coins,dp);
        int include = 0;
        if(amount-coins[n]>=0)
            include = check(n,amount-coins[n],coins,dp);
        
        return dp[n][amount] =  exclude+include;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return check(n-1,amount,coins,dp);
        
    }
};