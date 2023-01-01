class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        dp[0]=false;
        
        for(int i=1;i<=n;i++)
        {
            bool k = false;
            for(int j=1;j*j<=n;j++)
            {
                if(i-j*j>=0)
               k|=(!dp[i-j*j]);
            }
            dp[i] = k;
        }
        return dp[n];
        
    }
};