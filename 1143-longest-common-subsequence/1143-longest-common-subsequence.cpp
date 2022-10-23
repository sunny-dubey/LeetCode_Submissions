class Solution {
public:
    
    int check(int i, int j, string &x, string &y,vector<vector<int>> &dp)
    {
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i]==y[j])
            return dp[i][j] =  1 + check(i-1,j-1,x,y,dp);
        if(x[i]!=y[j])
            return  dp[i][j] = max(check(i-1,j,x,y,dp),check(i,j-1,x,y,dp));
        return 0;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
         
        return check(text1.size()-1,text2.size()-1,text1,text2,dp);
        
        
    }
};