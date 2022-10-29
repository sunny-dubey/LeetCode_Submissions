class Solution {
public:
    
    int rec(int n,vector<int> &dp)
    {
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        int ans = 0;
        for(int i=1;i<=2;i++){
            if(n-i>=0)
              ans+=rec(n-i,dp);
        }
        return dp[n] = ans;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};