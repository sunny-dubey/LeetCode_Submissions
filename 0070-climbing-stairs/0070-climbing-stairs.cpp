class Solution {
public:
    
    int check(int n, vector<int> &dp)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        int ans = check(n-1,dp) + check(n-2,dp);
        return dp[n] = ans;
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        int ans = check(n,dp);
        return ans;
    }
};