class Solution {
public:
    
    int check(int i, int j, string &s, string &t,vector<vector<int>> &dp)
    {
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1 + check(i-1,j-1,s,t,dp);
        else
            return dp[i][j] = max(check(i-1,j,s,t,dp),check(i,j-1,s,t,dp));
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int x = check(n-1,m-1,word1,word2,dp);
        return n+m-2*x;
    }
};