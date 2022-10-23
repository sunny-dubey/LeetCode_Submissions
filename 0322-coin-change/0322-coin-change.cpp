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
        int n = coins.size();
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i] = i/coins[0];
            else
                dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++)
        {
            
            for(int j=0;j<=amount;j++)
            {
                int exclude = dp[i-1][j];
                int include = INT_MAX;
                if(j-coins[i]>=0)
                    include = 1 + dp[i][j-coins[i]];
                
                dp[i][j] = min(include,exclude);
                
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
        
        
    }
};